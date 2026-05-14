#pragma once
#include "DynamicObject.h"
#include "box2d/box2d.h"
#include <iostream>
#include <list>
#include <set>
/// \brief Custom contact listener to handle collision events in Box2D. Overrides the default contact listener to provide custom behaviour when collisions occur.

class ContactListener : public b2ContactListener {

    public:
        std::set<uintptr_t> s_ptr;
        std::unordered_map<uintptr_t, Pig*>* pigLookup;
        std::unordered_map<uintptr_t, Structure*>* structLookup;
        Bird* activeBird = nullptr;
        ContactListener(std::unordered_map<uintptr_t, Pig*>* pigLookup, std::unordered_map<uintptr_t, Structure*>* structLookup)
        {
            this->pigLookup = pigLookup;
            this->structLookup = structLookup;
        }

        void SetActiveBird(Bird* bird)
        {
            activeBird = bird;
        }
    // Called when two fixtures begin to touch
    void BeginContact(b2Contact* contact) override {
        // Get the two fixtures involved
        b2Fixture* fixtureA = contact->GetFixtureA();
        b2Fixture* fixtureB = contact->GetFixtureB();

        uintptr_t a = fixtureA->GetBody()->GetUserData().pointer;
        uintptr_t b = fixtureB->GetBody()->GetUserData().pointer;

        bool aIsBird = (a == 100);
        bool bIsBird = (b == 100);
        
        if (aIsBird || bIsBird)
        {
            sf::Clock clock;
            if (activeBird->IsInFlight())
            {
                std::cout << "isCollide";
                activeBird->SetInFlight(false);
            }
        }

        if ((a == 100 && b > 2) || (b == 100 && a > 2)) 
        {
            uintptr_t pigID;
            uintptr_t structID;
            if (a == 100)
            {
                pigID = b;
                structID = b;
            }
            else if(b == 100)
            {
                pigID = a;
                structID = a;
            }
            Pig* pig = (*pigLookup)[pigID];
            Structure* structure = (*structLookup)[structID];
            if (pig)
            {
                b2Vec2 VelocityA = fixtureA->GetBody()->GetLinearVelocity();
                b2Vec2 VelocityB = fixtureB->GetBody()->GetLinearVelocity();
                float impactSpeed = (VelocityA - VelocityB).Length();
                float damage = impactSpeed * 10.0f;
                std::cout << "Pig Takes Damage";
                pig->TakeDamage(damage);
            }

            if (structure)
            {
                b2Vec2 VelocityA = fixtureA->GetBody()->GetLinearVelocity();
                b2Vec2 VelocityB = fixtureB->GetBody()->GetLinearVelocity();
                float impactSpeed = (VelocityA - VelocityB).Length();
                float damage = impactSpeed * 10.0f;
                std::cout << "Structure Takes Damage";
                structure->TakeDamage(damage);
            }
        }

        if ((a == 100 && b == 1) || (a == 1 && b == 100))
        {
            s_ptr.insert(fixtureB->GetBody()->GetUserData().pointer);
            std::cout << "Bird has hit the floor";
        }
    }
    // Called when two fixtures cease to touch
    void EndContact(b2Contact* contact) override {
        std::cout << "Collision Ended" << std::endl;
    }

    std::set<uintptr_t> getPointer() {
        return s_ptr;
    }

};