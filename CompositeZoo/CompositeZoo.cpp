// CompositeZoo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>


class IZoo
{
public :
    virtual void display() const = 0;
    virtual int counter() const = 0;
    virtual ~IZoo() = default;
};

class Animal : public IZoo
{
public : 
    explicit Animal(const std::string& name) : name(name) {}
    void display() const override 
    {
        std::cout << "Animal: " << name << std::endl;
    }

    int counter() const override 
    {
        return 1;
    }


private : 
    std::string name;
};


class ZoneZoo : public IZoo
{
public:
    explicit ZoneZoo(const std::string& name) : name(name) {}
    ~ZoneZoo()
    {
        for(IZoo* component : components)
        {
            delete component;
        }
    }

    void add(IZoo* component)
    {
        components.push_back(component);
    }

    void display() const override
    {
        std::cout << "Zone : " << name << std::endl;
        for (IZoo* component : components)
        {
            component->display();
        }
    }

    int counter() const override
    {
        int count = 0;
        for (IZoo* component : components)
        {
            count += component->counter();
            std::cout << "Il y a : " << count << " animaux\n";

        }return count;
    }


private :
    std::string name;
    std::vector<IZoo*> components;
};



int main()
{
    Animal* lion;
    lion = new Animal("Lion");
    Animal* elephant;
    elephant = new Animal("elephant");
    Animal* dolphin = new Animal("Dauphin");
    Animal* fish = new Animal("poisson");
    ZoneZoo* savanne = new ZoneZoo("Savane");
    savanne->add(lion);
    savanne->add(elephant);
    ZoneZoo* aquarium = new ZoneZoo("Aquarium");
    aquarium->add(dolphin);
    aquarium->add(fish);
    savanne->display();
    aquarium->display();
    Animal* panthere = new Animal("panthere");
    ZoneZoo* Foret = new ZoneZoo("Foret");
    Foret->add(panthere);
    Foret->display();
}

