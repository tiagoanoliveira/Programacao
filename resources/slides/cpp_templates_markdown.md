# Templates em C++: Guia Completo

## O que são Templates em C++?

Templates são mecanismos que permitem escrever código genérico em C++, permitindo que você crie funções e classes que trabalham com qualquer tipo de dado, sem precisar reescrever o código para cada tipo específico. Eles funcionam como "modelos" que o compilador usa para gerar automaticamente código específico para cada tipo utilizado.

## Tipos de Templates

### 1. Templates de Função

Templates de função permitem criar funções genéricas que operam com diferentes tipos de dados.

Sintaxe básica:
```cpp
template <typename T>
T funcao(T parametro) {
    // código
    return resultado;
}
```

### 2. Templates de Classe

Templates de classe permitem criar classes que funcionam com diferentes tipos de dados.

Sintaxe básica:
```cpp
template <typename T>
class Classe {
private:
    T membro;
public:
    Classe(T valor) : membro(valor) {}
    T getMembro() { return membro; }
};
```

### 3. Templates de Variável (C++14)

```cpp
template <typename T>
constexpr T pi = T(3.1415926535897932385);
```

### 4. Templates de Alias (C++11)

```cpp
template <typename T>
using Vetor = std::vector<T>;
```

## Como Usar Templates

1. **Declaração**: Use a palavra-chave `template` seguida dos parâmetros entre `<>`.
2. **Parâmetros**: Use `typename` ou `class` (equivalentes) para indicar tipos genéricos.
3. **Instanciação**: Acontece automaticamente quando você usa o template com um tipo específico.

## Vantagens dos Templates

1. **Reutilização de código**: Escreva uma vez, use com múltiplos tipos
2. **Type safety**: Verificação de tipos em tempo de compilação
3. **Performance**: Templates são resolvidos em tempo de compilação, sem overhead em runtime
4. **Flexibilidade**: Adaptação automática a diferentes tipos de dados
5. **Metaprogramação**: Permite computação em tempo de compilação
6. **STL**: A biblioteca padrão de C++ é construída sobre templates

## Desvantagens e Desafios

1. **Mensagens de erro complexas**: Erros em templates podem gerar mensagens difíceis de entender
2. **Tempo de compilação**: Uso extensivo pode aumentar o tempo de compilação
3. **Código binário maior**: Cada instanciação gera código separado
4. **Curva de aprendizado**: Conceitos avançados podem ser complexos

## Exemplos Práticos

### 1. Template de Função Básico
```cpp
template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

// Uso:
maximo(10, 20);       // Instancia para int
maximo(3.14, 2.71);   // Instancia para double
maximo('a', 'z');     // Instancia para char
```

### 2. Template de Classe Básico
```cpp
template <typename T>
class Pilha {
private:
    std::vector<T> elementos;
public:
    void push(T const& elemento) {
        elementos.push_back(elemento);
    }
    
    T pop() {
        if (elementos.empty()) {
            throw std::out_of_range("Pilha vazia");
        }
        T topo = elementos.back();
        elementos.pop_back();
        return topo;
    }
    
    bool vazia() const {
        return elementos.empty();
    }
    
    size_t tamanho() const {
        return elementos.size();
    }
};

// Uso:
Pilha<int> pilhaInt;
pilhaInt.push(1);
pilhaInt.push(2);

Pilha<std::string> pilhaString;
pilhaString.push("Olá");
pilhaString.push("Mundo");
```

### 3. Template com Múltiplos Parâmetros
```cpp
template <typename T, typename U>
auto soma(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Uso:
soma(5, 3.14);  // Soma int com double, retorna double
```

### 4. Template com Parâmetro não-tipo
```cpp
template <typename T, int N>
class Array {
private:
    T dados[N];
public:
    T& operator[](int indice) {
        return dados[indice];
    }
    
    const T& operator[](int indice) const {
        return dados[indice];
    }
    
    int tamanho() const {
        return N;
    }
};

// Uso:
Array<double, 5> array;
```

### 5. Especialização de Template
```cpp
template <typename T>
bool ehZero(T valor) {
    return valor == 0;
}

// Especialização para ponteiros
template <typename T>
bool ehZero(T* ponteiro) {
    return ponteiro == nullptr;
}

// Uso:
ehZero(0);       // Usa a versão geral
int* ptr = nullptr;
ehZero(ptr);     // Usa a especialização para ponteiros
```

### 6. Templates Variadic (C++11)
```cpp
template <typename T>
T soma_valores(T v) {
    return v;
}

template <typename T, typename... Args>
T soma_valores(T primeiro, Args... resto) {
    return primeiro + soma_valores<T>(resto...);
}

// Uso:
soma_valores(1, 2, 3, 4, 5);  // Soma todos os valores: 15
```

### 7. Template com SFINAE (Substitution Failure Is Not An Error)
```cpp
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
ehPar(T numero) {
    return numero % 2 == 0;
}

// Uso:
ehPar(15);  // Retorna false
// ehPar(3.14);  // Erro de compilação - tipo não é integral
```

### 8. Template com valor padrão
```cpp
template <typename T = int>
class Container {
private:
    T valor;
public:
    Container(T v = T{}) : valor(v) {}
    T get() const { return valor; }
};

// Uso:
Container<> defaultContainer;  // Usa o tipo padrão (int)
Container<double> doubleContainer(3.14);
```

### 9. Uso de auto com templates (C++14)
```cpp
template <typename T>
auto quadrado(T x) {
    return x * x;
}

// Uso:
quadrado(7);    // Retorna 49 (int)
quadrado(2.5);  // Retorna 6.25 (double)
```

### 10. Conceitos (C++20)
```cpp
template <typename T>
concept Numerico = std::is_arithmetic_v<T>;

template <Numerico T>
T multiplicar(T a, T b) {
    return a * b;
}

// Uso:
multiplicar(5, 3);      // Funciona
// multiplicar("a", "b");  // Erro de compilação - não é numérico
```

## Programa Completo com Exemplos

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// 1. Template de Função Básico
template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

// 2. Template de Classe Básico
template <typename T>
class Pilha {
private:
    std::vector<T> elementos;
public:
    void push(T const& elemento) {
        elementos.push_back(elemento);
    }
    
    T pop() {
        if (elementos.empty()) {
            throw std::out_of_range("Pilha vazia");
        }
        T topo = elementos.back();
        elementos.pop_back();
        return topo;
    }
    
    bool vazia() const {
        return elementos.empty();
    }
    
    size_t tamanho() const {
        return elementos.size();
    }
};

// 3. Template com Múltiplos Parâmetros
template <typename T, typename U>
auto soma(T a, U b) -> decltype(a + b) {
    return a + b;
}

// 4. Template com Parâmetro não-tipo
template <typename T, int N>
class Array {
private:
    T dados[N];
public:
    T& operator[](int indice) {
        return dados[indice];
    }
    
    const T& operator[](int indice) const {
        return dados[indice];
    }
    
    int tamanho() const {
        return N;
    }
};

// 5. Especialização de Template
template <typename T>
bool ehZero(T valor) {
    return valor == 0;
}

// Especialização para ponteiros
template <typename T>
bool ehZero(T* ponteiro) {
    return ponteiro == nullptr;
}

// 6. Templates Variadic (C++11)
template <typename T>
T soma_valores(T v) {
    return v;
}

template <typename T, typename... Args>
T soma_valores(T primeiro, Args... resto) {
    return primeiro + soma_valores<T>(resto...);
}

// 7. Template com SFINAE (Substitution Failure Is Not An Error)
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
ehPar(T numero) {
    return numero % 2 == 0;
}

// 8. Template com valor padrão
template <typename T = int>
class Container {
private:
    T valor;
public:
    Container(T v = T{}) : valor(v) {}
    T get() const { return valor; }
};

// 9. Uso de auto com templates (C++14)
template <typename T>
auto quadrado(T x) {
    return x * x;
}

// 10. Conceitos (C++20)
/*
template <typename T>
concept Numerico = std::is_arithmetic_v<T>;

template <Numerico T>
T multiplicar(T a, T b) {
    return a * b;
}
*/

int main() {
    // Exemplo 1: Template de função
    std::cout << "Máximo entre 10 e 20: " << maximo(10, 20) << std::endl;
    std::cout << "Máximo entre 3.14 e 2.71: " << maximo(3.14, 2.71) << std::endl;
    std::cout << "Máximo entre 'a' e 'z': " << maximo('a', 'z') << std::endl;
    
    // Exemplo 2: Template de classe
    Pilha<int> pilhaInt;
    pilhaInt.push(1);
    pilhaInt.push(2);
    pilhaInt.push(3);
    std::cout << "\nPilha de inteiros - tamanho: " << pilhaInt.tamanho() << std::endl;
    std::cout << "Elemento do topo: " << pilhaInt.pop() << std::endl;
    
    Pilha<std::string> pilhaString;
    pilhaString.push("Olá");
    pilhaString.push("Mundo");
    std::cout << "\nPilha de strings - tamanho: " << pilhaString.tamanho() << std::endl;
    std::cout << "Elemento do topo: " << pilhaString.pop() << std::endl;
    
    // Exemplo 3: Múltiplos parâmetros
    std::cout << "\nSoma de int e double: " << soma(5, 3.14) << std::endl;
    
    // Exemplo 4: Parâmetros não-tipo
    Array<double, 5> array;
    for (int i = 0; i < array.tamanho(); i++) {
        array[i] = i * 1.1;
    }
    std::cout << "\nArray - elemento 3: " << array[3] << std::endl;
    
    // Exemplo 5: Especialização
    int* ptr = nullptr;
    std::cout << "\nÉ zero (0): " << (ehZero(0) ? "Sim" : "Não") << std::endl;
    std::cout << "É zero (nullptr): " << (ehZero(ptr) ? "Sim" : "Não") << std::endl;
    
    // Exemplo 6: Variadic templates
    std::cout << "\nSoma variádica: " << soma_valores(1, 2, 3, 4, 5) << std::endl;
    
    // Exemplo 7: SFINAE
    std::cout << "\n15 é par? " << (ehPar(15) ? "Sim" : "Não") << std::endl;
    
    // Exemplo 8: Valor padrão
    Container<> defaultContainer;  // Usa o tipo padrão (int)
    Container<double> doubleContainer(3.14);
    std::cout << "\nValor padrão: " << defaultContainer.get() << std::endl;
    std::cout << "Valor double: " << doubleContainer.get() << std::endl;
    
    // Exemplo 9: auto com templates
    std::cout << "\nQuadrado de 7: " << quadrado(7) << std::endl;
    std::cout << "Quadrado de 2.5: " << quadrado(2.5) << std::endl;
    
    // Exemplo 10: Conceitos (C++20)
    // std::cout << "\nMultiplicação com conceitos: " << multiplicar(5, 3) << std::endl;
    
    return 0;
}
```

## Casos de Uso Comuns

1. **Estruturas de dados genéricas**: Listas, árvores, grafos
2. **Containers**: Como os da STL (vector, list, map)
3. **Algoritmos**: Funções genéricas (sort, find, transform)
4. **Smart pointers**: unique_ptr, shared_ptr (gestão de memória)
5. **Metaprogramação**: Cálculos em tempo de compilação

## Técnicas Avançadas

1. **Traits classes**: Fornecem informações sobre tipos
2. **Policy-based design**: Componentes modulares via templates
3. **Expression templates**: Otimização de expressões matemáticas
4. **Tag dispatching**: Seleção de implementação via tags
5. **CRTP (Curiously Recurring Template Pattern)**: Polimorfismo estático

## Dicas para Usar Templates Efetivamente

1. **Mantenha simples**: Use apenas quando necessário
2. **Documente bem**: Explique requisitos de tipos
3. **Teste com vários tipos**: Garanta compatibilidade
4. **Evite código duplicado**: Extraia comportamento comum
5. **Use conceitos (C++20)**: Para restrições mais claras e melhores mensagens de erro

## Evolução dos Templates em C++

### C++98/03
- Templates básicos de função e classe
- Especialização de templates

### C++11
- Variadic templates
- Alias templates (`using`)
- Expressões lambda genéricas
- `decltype` e `auto`

### C++14
- Templates de variável
- `auto` em parâmetros de função lambda

### C++17
- Dedução de tipo para construtores de classe template
- Template argument deduction 
- `if constexpr`

### C++20
- Conceitos (concepts)
- Restrições (constraints)
- Ranges
- Módulos

## Bibliografia Recomendada

1. "C++ Templates: The Complete Guide" - David Vandevoorde, Nicolai M. Josuttis
2. "Modern C++ Design" - Andrei Alexandrescu
3. "Effective Modern C++" - Scott Meyers
4. "C++ Template Metaprogramming" - David Abrahams, Aleksey Gurtovoy
5. "The C++ Standard Library" - Nicolai M. Josuttis