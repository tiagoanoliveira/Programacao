//
// Created by tiago-oliveira on 17-06-2025.
//
#include "Hanoi.h"
#include <sstream>

// Construtor: inicializa uma torre vazia com capacidade para n_disks
Tower::Tower(int n_disks) : n_disks(n_disks), idx_top(-1) {
    disks_ = new int[n_disks];
}

// Destrutor: libera a memória alocada para os discos
Tower::~Tower() {
    delete[] disks_;
}

// Retorna o disco no topo (0 se a torre estiver vazia)
int Tower::top() const {
    return (idx_top >= 0) ? disks_[idx_top] : 0;
}

// Adiciona um disco ao topo se houver espaço
void Tower::add(int disk) {
    if (idx_top + 1 < n_disks) {
        disks_[++idx_top] = disk;
    }
}

// Remove o disco do topo (não faz nada se vazia)
void Tower::remove() {
    if (idx_top >= 0) {
        idx_top--;
    }
}

// Retorna a representação em string da torre (ex: "[3 2 1]")
string Tower::str() const {
    ostringstream oss;
    oss << "[ ";
    for (int i = 0; i <= idx_top; ++i) {
        oss << disks_[i] << " ";
    }
    oss << "]";
    return oss.str();
}
void Hanoi::move(std::initializer_list<disk_move> dmoves) {
    for (const auto& dm : dmoves) {
        // Verifica se as torres são válidas (0-2)
        if (dm.from < 0 || dm.from > 2 || dm.to < 0 || dm.to > 2) continue;

        Tower& from = towers_[dm.from];
        Tower& to = towers_[dm.to];
        int disk = from.top();

        // Verifica se a torre de origem não está vazia
        if (disk == 0) continue;

        int to_disk = to.top();

        // Verifica se a torre de destino pode receber o disco
        if (to_disk != 0 && to_disk < disk) continue;

        // Executa o movimento
        from.remove();
        to.add(disk);
    }
}
int main() {
    {
        Tower t(5);     std::cout << "a. " << t.top() << ' ' << t.str() << std::endl; // initially
        t.add(5);    std::cout << "b. " << t.top() << ' ' << t.str() << std::endl; // add 5
        t.add(4);    std::cout << "c. " << t.top() << ' ' << t.str() << std::endl; // add 4
        t.remove();  std::cout << "d. " << t.top() << ' ' << t.str() << std::endl; // remove 4
        t.add(3);    std::cout << "e. " << t.top() << ' ' << t.str() << std::endl; // add 3
        t.add(2);    std::cout << "f. " << t.top() << ' ' << t.str() << std::endl; // add 2
        t.remove();  std::cout << "g. " << t.top() << ' ' << t.str() << std::endl; // remove 2
        t.remove();  std::cout << "h. " << t.top() << ' ' << t.str() << std::endl; // remove 3
        t.remove();  std::cout << "i. " << t.top() << ' ' << t.str() << std::endl; // remove 5
        t.add(1);    std::cout << "j. " << t.top() << ' ' << t.str() << std::endl; // add 1
        t.remove();  std::cout << "k. " << t.top() << ' ' << t.str() << std::endl; // remove 1
    }
    {
        Hanoi h(5);
        std::cout << h.str() << std::endl;
    }
    {
        // contains invalid moves (I)
        Hanoi h(3);
        h.move({ {0, 2}, {1, 2} /* I */, {0, 2} /* I */, {0, 1}, {2, 1}, {0, 2}, {1, 1} /* I */ });
        std::cout << h.str() << std::endl;
    }
    {
        // complete solution for 2 disks
        Hanoi h(2);
        h.move({ {0, 1}, {0, 2}, {1, 2} });
        std::cout << h.str() << std::endl;
    }
    return 0;
}