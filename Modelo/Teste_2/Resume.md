## 1. Classes em C++

### Conceitos Fundamentais

Uma classe em C++ é um tipo de dados declarado usando a palavra-chave `class` [^1]. As classes servem como modelos ou "blueprints" para criar objetos, definindo tanto atributos (variáveis) quanto comportamentos (funções) [^1][^2].

A diferença principal entre uma `class` e uma `struct` em C++ é mínima: em uma classe, as declarações são privadas por padrão, enquanto em uma struct são públicas por padrão [^1].

### Estrutura Básica de uma Classe

```cpp
class fraction {
public:
    // Construtores
    fraction(int n, int d = 1);
    fraction();
    fraction(const fraction& f);
    
    // Funções membro
    int numerator() const;
    int denominator() const;
    void add(const fraction& f);
    
private:
    int num, den;
};
```


### Campos e Funções Membro

Os campos membro (member fields) são variáveis que cada objeto da classe possui [^1]. Estes campos são tipicamente privados para esconder o estado interno dos objetos [^1].

As funções membro permitem que o estado do objeto seja consultado ou modificado [^1]. Funções marcadas como `const` não alteram os campos membro, e tentativas de modificação resultam em erros de compilação [^1].

### Construtores e Destrutores

Os construtores são funções especiais com o mesmo nome da classe que inicializam objetos [^1][^2]. Existem diferentes tipos:

- **Construtor padrão**: sem parâmetros
- **Construtor de cópia**: aceita uma referência const para outro objeto da mesma classe
- **Construtores parametrizados**: aceitam argumentos específicos [^2]

```cpp
fraction::fraction(int n, int d) : num(n), den(d) {
    reduce(); // converter para forma irredutível
}

fraction::fraction() : num(0), den(1) {}

fraction::fraction(const fraction& f) : num(f.num), den(f.den) {}
```

O destrutor é uma função especial chamada automaticamente quando um objeto sai de escopo [^2]. Sua função principal é liberar recursos internos utilizados pelo objeto [^2].

### Visibilidade e Encapsulamento

C++ oferece três modificadores de acesso [^1]:

- **public**: acessível de qualquer lugar
- **private**: acessível apenas dentro da própria classe
- **protected**: acessível na classe e em suas subclasses


## 2. Classes Template

### Conceito e Sintaxe

Classes template permitem criar classes genéricas que funcionam com diferentes tipos de dados [^3]. A declaração é similar aos templates de função [^3]:

```cpp
template <typename T>
class polynomial {
public:
    polynomial(const std::vector<T>& c);
    
private:
    std::vector<T> coeff;
};
```


### Implementação e Uso

O código de uma classe template geralmente reside em um único arquivo header, pois a compilação separada não é possível [^3]:

```cpp
template <typename T>
class simplevector {
public:
    simplevector(int initial_capacity = 5);
    void add(const T& elem);
    T& at(int index);
    const T& at(int index) const;
    
private:
    int capacity;
    int size;
    T* elements;
};
```

Exemplo de uso:

```cpp
simplevector<int> v(2);
v.add(-1);
v.add(2);
simplevector<double> v2;
polynomial<fraction> p({1, 2, 3, 4});
polynomial<double> q({0.5, 0.75});
```


### Templates com Múltiplos Parâmetros

É possível criar templates com vários parâmetros de tipo [^3]:

```cpp
template <typename T, typename U>
class pair {
public:
    pair(const T& a, const U& b) : first(a), second(b) {}
    T first;
    U second;
};

pair<int, std::string> a(2024, "leic");
pair<std::string, pair<int,int>> b("leic", {2023, 2024});
```


## 3. Compilação Separada

### Organização de Arquivos

A compilação separada permite dividir o código em diferentes arquivos para melhor organização e reutilização [^1]. Classes devem ser declaradas em arquivos header (.hpp) e implementadas em arquivos source (.cpp) [^1].

### Header Guards

Os header guards são uma prática padrão para arquivos header em C++, prevenindo inclusões repetidas do mesmo arquivo [^1]:

```cpp
#ifndef FRACTION_HPP
#define FRACTION_HPP

namespace leic {
    class fraction {
        // declarações da classe
    };
}

#endif
```


### Exemplo de Estrutura

**fraction.hpp:**

```cpp
#ifndef FRACTION_HPP
#define FRACTION_HPP

class fraction {
public:
    fraction(int num, int den = 1);
    int numerator() const;
    int denominator() const;
    
private:
    int num, den;
};

#endif
```

**fraction.cpp:**

```cpp
#include "fraction.hpp"

fraction::fraction(int n, int d) : num(n), den(d) {
    // implementação
}

int fraction::numerator() const {
    return num;
}
```


## 4. Herança de Classes

### Conceitos Fundamentais

A herança permite criar subclasses que herdam funcionalidade de uma classe base [^4]. A herança deve refletir uma relação "é um" entre os conceitos representados pelas classes [^4].

```cpp
class person {
public:
    person(int id, const std::string& name);
    int id() const;
    const std::string& name() const;
    
private:
    int pid;
    std::string pname;
};

class teacher : public person {
public:
    teacher(int id, const std::string& name, const std::string& dept);
    const std::string& department() const;
    
private:
    std::string tdepartment;
};
```


### Construtores em Herança

Construtores de subclasses devem chamar o construtor da classe base, tipicamente através de uma lista de inicialização [^4]:

```cpp
teacher::teacher(int id, const std::string& name, const std::string& dept)
    : person(id, name), tdepartment(dept) {
}
```


### Modificadores de Acesso Protected

O modificador `protected` permite que declarações sejam acessíveis na classe declarante e em suas subclasses, mas não externamente [^4]:

```cpp
class person {
protected:
    int pid;
    std::string pname;
};
```


### Polimorfismo e Funções Virtuais

Funções virtuais permitem redefinição polimórfica em subclasses [^4]. Quando uma função é declarada como `virtual` na classe base, a versão correta é chamada baseada no tipo real do objeto:

```cpp
class person {
public:
    virtual void print(std::ostream& out) const;
};

class teacher : public person {
public:
    void print(std::ostream& out) const override;
};
```


## 5. Sobrecarga de Operadores

### Conceito e Motivação

A sobrecarga de operadores permite associar comportamento definido pelo programador aos operadores padrão como `+`, `-`, `==` [^5]. Isso torna os programas mais concisos, mas deve ser usada criteriosamente [^5].

### Implementação de Operadores

Operadores podem ser implementados como funções membro ou funções externas [^5]:

**Como função membro:**

```cpp
class fraction {
public:
    bool operator==(const fraction& f) const;
    fraction& operator+=(const fraction& f);
};

bool fraction::operator==(const fraction& f) const {
    return num * f.den == f.num * den;
}
```

**Como função externa:**

```cpp
bool operator==(const fraction& a, const fraction& b) {
    return a.numerator() * b.denominator() == 
           b.numerator() * a.denominator();
}
```


### Operadores Comuns

**Operadores de Comparação:**

```cpp
bool operator==(const fraction& f) const;
bool operator!=(const fraction& f) const;
bool operator<(const fraction& f) const;
bool operator<=(const fraction& f) const;
bool operator>(const fraction& f) const;
bool operator>=(const fraction& f) const;
```

**Operador de Atribuição:**

```cpp
fraction& operator=(const fraction& f) {
    num = f.num;
    den = f.den;
    return *this;
}
```

**Operadores de Stream:**

```cpp
std::ostream& operator<<(std::ostream& out, const fraction& f) {
    out << f.numerator();
    if (f.denominator() != 1) {
        out << "/" << f.denominator();
    }
    return out;
}
```


## 6. Exceções

### Motivação e Conceitos

As exceções em C++ fornecem uma forma estruturada de lidar com erros durante a execução [^6]. Elas permitem sinalizar erros no ponto onde são detectados usando `throw` e tratá-los em outro ponto usando blocos `try-catch` [^6].

### Sintaxe Básica

```cpp
try {
    std::cout << "Enter a positive integer: ";
    int n;
    std::cin >> n;
    if (n <= 0) {
        throw std::logic_error("expected positive integer");
    }
    std::cout << "The number is " << n << std::endl;
}
catch (std::logic_error& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```


### Hierarquia de Exceções

C++ define uma hierarquia padrão de exceções no header `<stdexcept>` [^6]:

- `std::exception` (classe base)
    - `std::logic_error`
        - `std::invalid_argument`
        - `std::out_of_range`
        - `std::length_error`
    - `std::runtime_error`
        - `std::overflow_error`
        - `std::underflow_error`


### Exceções Personalizadas

É possível criar classes de exceção personalizadas derivando das exceções padrão [^6]:

```cpp
class invalid_time : public std::logic_error {
public:
    invalid_time() : logic_error("invalid time") {}
};

class timeofday {
public:
    timeofday(int h, int m) {
        if (h < 0 || h > 23 || m < 0 || m > 59) {
            throw invalid_time();
        }
    }
};
```


### Múltiplos Blocos Catch

É possível ter vários blocos catch para diferentes tipos de exceções [^6]:

```cpp
try {
    // código que pode lançar exceções
}
catch (std::out_of_range& e) {
    // tratar out_of_range
}
catch (std::logic_error& e) {
    // tratar outros logic_error
}
catch (std::exception& e) {
    // tratar qualquer outra exceção padrão
}
catch (...) {
    // tratar qualquer tipo de exceção
}
```


## 7. Standard Template Library (STL)

### Visão Geral

A STL é um conjunto de classes template e funções compostas por [^7][^8]:

- **Containers**: estruturas de dados como `std::vector`, `std::list`
- **Iterators**: para travessia de containers
- **Algorithms**: operações comuns como `std::sort`


### Containers Sequenciais

**std::vector**: Array dinâmico com elementos armazenados contiguamente [^7][^8]

```cpp
std::vector<int> v{1, 2, 3};
v.push_back(4);
```

**std::list**: Lista duplamente ligada [^7][^8]

```cpp
std::list<std::string> l{"a", "b", "c"};
l.push_front("z");
```

**std::deque**: Combina vector e lista para inserção rápida no início [^7][^8]

```cpp
std::deque<std::string> dq{"a", "b", "c"};
dq.push_front("z");
dq.push_back("d");
```


### Iterators

Iterators são objetos que permitem percorrer elementos de um container [^7][^8]. Têm posição associada e elemento correspondente:

```cpp
std::vector<int> c{2, -5, 6, 7, -9};
int sum = 0;
for (auto itr = c.begin(); itr != c.end(); ++itr) {
    sum += *itr;
}
```

**Range-based for loops** são mais convenientes e usam iterators implicitamente [^7][^8]:

```cpp
std::vector<int> c{2, -5, 6, 7, -9};
int sum = 0;
for (int v : c) {
    sum += v;
}
```


### Operações Comuns

Todos os containers STL compartilham operações básicas [^7][^8]:

- `size()`: número de elementos
- `empty()`: verifica se está vazio
- `begin()`, `end()`: iterators para percorrer
- `insert()`, `erase()`: inserir/remover elementos
- `clear()`: remover todos os elementos


### Complexidade Algorítmica

Diferentes containers têm diferentes complexidades para operações [^7][^8]:


| Operação | vector | list | deque |
| :-- | :-- | :-- | :-- |
| push_front | N/A | O(1) | O(1) |
| push_back | O(1) | O(1) | O(1) |
| at/operator[] | O(1) | O(n) | O(1) |
| insert/remove | O(n) | O(1) | O(1) |

## 8. Function Objects e Lambda Expressions

### Function Objects (Functors)

Function objects são objetos cujo tipo define `operator()` [^9]. Podem ser invocados como funções através deste operador:

```cpp
class interval {
private:
    int start, end;
public:
    interval(int start, int end) : start(start), end(end) {}
    
    bool operator()(int x) const {
        return x >= start && x <= end;
    }
};

interval in(20, 40);
std::cout << in(25); // true
std::cout << in(50); // false
```

Function objects são úteis para personalizar comportamento em algoritmos STL [^9]:

```cpp
std::vector<int> v{1, 23, 5, 6, 32, 0, 45, 3};
std::cout << std::count_if(v.begin(), v.end(), interval(20, 40)); // 2
```


### Lambda Expressions

Lambda expressions são funções anônimas que permitem definições concisas inline [^9]. A sintaxe geral é:

```
[capture](arguments) -> return_type { body }
```

**Exemplo básico:**

```cpp
auto f = [](int x, int y) -> int {
    return x * x + y;
};
std::cout << f(1, 1); // 2
std::cout << f(2, 2); // 6
```

O tipo de retorno pode ser omitido quando inferível pelo compilador [^9]:

```cpp
auto f = [](int x, int y) {
    return x * x + y;
};
```


### Capture Clauses

Lambda expressions podem usar variáveis do contexto através de capture clauses [^9]:

**Capture por valor** (`[=]`): captura todas as variáveis por valor

```cpp
int i = 123;
auto f = [=](int x) { return x + i; };
std::cout << f(1); // 124
i = 321;
std::cout << f(1); // 124 (i ainda é 123 na lambda)
```

**Capture por referência** (`[&]`): captura todas as variáveis por referência

```cpp
int i = 123;
auto f = [&](int x) { return x + i; };
std::cout << f(1); // 124
i = 321;
std::cout << f(1); // 322 (i agora é 321)
```

**Capture mista**: especificar variáveis individuais

```cpp
int a = 10, b = 20;
auto f = [a, &b](int x) { return x + a + b; }; // a por valor, b por referência
```


### Uso com Algoritmos STL

Lambda expressions são frequentemente usadas com algoritmos STL [^9]:

```cpp
std::vector<int> v{1, 23, 5, 6, 32, 0, 45, 3};

// Contar elementos em um intervalo
int a = 20, b = 40;
std::cout << std::count_if(v.begin(), v.end(), 
    [a, b](int x) { return x >= a && x <= b; });

// Modificar elementos
std::for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
```

  <p align="center">
<img src="WhatsApp%20Image%202025-06-17%20at%2010.14.51.jpeg" width="100%" height="100%">
<img src="WhatsApp%20Image%202025-06-17%20at%2010.21.33.jpeg" width="100%">
<img src="WhatsApp%20Image%202025-06-17%20at%2010.21.33(1).jpeg" width="100%">
<img src="WhatsApp%20Image%202025-06-17%20at%2010.28.18.jpeg" width="100%" height="100%">
</p>

