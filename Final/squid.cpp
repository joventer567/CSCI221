#include "squid.hpp"


Squid::Squid() {
    health = 20;
    squid_name = "Generic squid";
}

Squid::Squid(int life, std::string name) {
    health = life;
    squid_name = name;

}

Squid::~Squid() {

}

void Squid::punch() {
    health -= 4;
}

void Squid::strong_punch() {
    health -= 9;
}

void Squid::weak_punch() {
    health -= 1;
}

void Squid::fire() {
    health -= 2;
}

void Squid::smash_attack() {
    health -= 10;
}

void Squid::heal() {
    health += 3;
}

bool Squid::dead() {
    if (health <= 0) {
        return true;
    }
    return false;
}

int Squid::return_health() {
    return health;
}

void Squid::instakill() {
    health = 0;
}

std::string Squid::getName() {
    return squid_name;
}