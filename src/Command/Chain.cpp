#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Scrim.hpp"
#include "Logger.hpp"

#include "Command/Save.hpp"
#include <filesystem>

namespace prog {
    namespace command {

        // Conjunto estático para rastrear os scrims atualmente sendo processados
        // Usado para detectar inclusões recursivas (scrim A inclui scrim B que inclui scrim A)
        std::set<std::string> Chain::active_scrims_;

        // Construtor: inicializa o comando com nome "chain" e armazena a lista de ficheiros scrim
        Chain::Chain(const std::vector<std::string>& files) : Command("chain"), scrim_filenames_(files) {}

        // Destrutor padrão
        Chain::~Chain() {}

        // Método principal que aplica o comando Chain a uma imagem
        // Processa sequencialmente todos os ficheiros scrim especificados
        Image* Chain::apply(Image* img) {
            // Ponteiro para a imagem atual (começa com a imagem de entrada)
            Image* current = img;

            // Itera através de todos os ficheiros scrim especificados
            for (const auto& file : scrim_filenames_) {
                // Converte o caminho do ficheiro para caminho absoluto
                // Isto é importante para comparações consistentes na deteção de recursão
                const auto abs_path = std::filesystem::absolute(file).string();

                // Verifica se este scrim já está sendo processado (deteção de recursão)
                if (active_scrims_.count(abs_path)) {
                    *Logger::out() << "Chain: Recursive inclusion of '" << file << "' detected, skipping.\n";
                    continue; // Pula este ficheiro para evitar recursão infinita
                }

                // Marca este scrim como ativo (sendo processado)
                active_scrims_.insert(abs_path);

                // Cria um parser para ler o ficheiro scrim
                ScrimParser parser;
                Scrim* inner_scrim = parser.parseScrim(file);

                // Verifica se o ficheiro foi carregado com sucesso
                if (!inner_scrim) {
                    *Logger::err() << "Chain: Could not load scrim file '" << file << "'\n";
                    // Remove da lista de ativos já que não foi processado
                    active_scrims_.erase(abs_path);
                    continue; // Pula para o próximo ficheiro
                }

                // Processa todos os comandos do scrim carregado
                for (auto* cmd : inner_scrim->getCommands()) {
                    auto name = cmd->name();

                    // Ignora comandos específicos que não devem ser executados em chain
                    // Save, Open e Blank são comandos de controlo de ficheiros/estado
                    if (name == "Save" || name == "Open" || name == "Blank") {
                        continue; // Ignora sem log (comentário original em português)
                    }

                    // Aplica o comando à imagem atual
                    // O resultado torna-se a nova imagem atual para o próximo comando
                    current = cmd->apply(current);
                }

                // Liberta a memória do scrim carregado
                delete inner_scrim;

                // Remove este scrim da lista de ativos (processamento concluído)
                active_scrims_.erase(abs_path);
            }

            // Retorna a imagem final após todos os processamentos
            return current;
        }

        // Método para converter o comando numa string representativa
        // Útil para debug, logging ou serialização
        std::string Chain::toString() const {
            std::ostringstream ss;
            // Começa com o nome do comando
            ss << name();
            // Adiciona todos os nomes dos ficheiros scrim
            for (const auto& f : scrim_filenames_) ss << " " << f;
            return ss.str();
        }
    }
}