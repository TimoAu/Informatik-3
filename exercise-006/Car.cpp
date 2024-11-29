#include"Car.hpp"
void PorscheTaycan::setEngine(){
    Engine = electric.engineType;
}

void PorscheTaycan::setSuspension(){
    Suspension = electric.suspensionType;
}

void DodgeRAM::setEngine(){
    Engine = V8.engineType;
}

void DodgeRAM::setSuspension(){
    Suspension = V8.suspensionType;
}

void Polo::setEngine(){
    Engine = V6.engineType;
}

void Polo::setSuspension(){
    Suspension = V6.suspensionType;
}