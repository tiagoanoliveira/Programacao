//
// Created by tiago-oliveira on 22-04-2025.
//
#include <cmath>
#include "Point2d.h"
#include <iostream>
#include <iomanip>

/**
 * Translada este ponto pelas coordenadas do ponto fornecido
 * @param t Coordenadas de translação
 */
void Point2d::translate(const Point2d& t) {
    // Adiciona as coordenadas x e y do ponto t às coordenadas deste ponto
    this->x += t.x;
    this->y += t.y;
}

/**
 * Calcula a distância euclidiana entre este ponto e o ponto fornecido
 * @param p Ponto para calcular a distância
 * @return A distância euclidiana entre os dois pontos
 */
double Point2d::distance_to(const Point2d& p) const {
    // Calcula a distância euclidiana usando a fórmula: sqrt((x1-x2)² + (y1-y2)²)
    double dx = this->x - p.x;
    double dy = this->y - p.y;
    return sqrt(dx*dx + dy*dy);
}

int main () {
    { Point2d a { 1.0, 2.1 };
        a.translate({ -0.3, 0.5 });
        std::cout << std::fixed << std::setprecision(2)
             << a.get_x() << ' ' << a.get_y() << '\n'; }
    { Point2d a { 1.0, 2.1 }, b { 2.0, 3.1 };
        std::cout << std::fixed << std::setprecision(2)
             << a.distance_to(b) << '\n'; }
    { Point2d a { 0, 0 }; Point2d b = a;
        a.translate({ 0, 0 });
        std::cout << std::fixed << std::setprecision(2)
             << a.get_x() << ' ' << a.get_y() << ' '
             << a.distance_to(b) << '\n'; }
    { Point2d a { 0, 1 }; Point2d b = a;
        a.translate({ 1.5, 0 });
        std::cout << std::fixed << std::setprecision(2)
             << a.get_x() << ' ' << a.get_y() << ' '
             << a.distance_to(b) << '\n'; }
    { Point2d a { 1, 0 }; Point2d b = a;
        a.translate({ -1, 2.5 });
        std::cout << std::fixed << std::setprecision(2)
             << a.get_x() << ' ' << a.get_y() << ' '
             << a.distance_to(b) << '\n'; }
    return 0;
}