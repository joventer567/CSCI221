#include <string>
#ifndef SQUID_HPP
#define SQUID_HPP

class Squid {

    private:
        int health;
        std::string squid_name;

    public:
        Squid();
        Squid(int life, std::string name);
        ~Squid();
        
        void punch();
        void strong_punch();
        void weak_punch();
        void smash_attack();
        void fire();
        void heal();
        bool dead();
        int return_health();
        void instakill();
        std::string getName();
};

#endif
