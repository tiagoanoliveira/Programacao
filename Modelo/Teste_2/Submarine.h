#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Floatable.h"
#include <string>

class Submarine : public Floatable {
public:
    // Construtor
    Submarine(int id, double mass, const std::string& captain)
        : Floatable(id, mass), captain_(captain) {}

    // Devolve o nome do capitão
    std::string captain() const {
        return captain_;
    }

    // Implementação do método virtual puro buoyancy()
    double buoyancy() const override {
        static constexpr double g = 9.81;   // aceleração gravítica (m/s^2)
        static constexpr double rho = 1025; // densidade da água do mar (kg/m^3)
        return mass() * g * rho;
    }

private:
    std::string captain_;
};

#endif // SUBMARINE_H
