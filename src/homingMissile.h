#ifndef HOMING_MISSLE_H
#define HOMING_MISSLE_H

#include "spaceObject.h"

class HomingMissile : public SpaceObject, public Updatable
{
    const static float speed = 500.0f;
    const static float turnSpeed = 100.0f;
    const static float totalLifetime = 12.0f;
    
    float lifetime;
public:
    P<SpaceObject> owner; //Only valid on server.
    int32_t target_id;

    HomingMissile();

    virtual void draw3D();
    virtual void draw3DTransparent();
    virtual void drawOnRadar(sf::RenderTarget& window, sf::Vector2f position, float scale, bool long_range);
    virtual void update(float delta);
    
    virtual bool canBeTargetedByPlayer() { return true; }
    
    virtual void collision(Collisionable* target);
    virtual void takeDamage(float damageAmount, sf::Vector2f damageLocation, EDamageType type, int frequency=-1) { if (type != DT_Kinetic) destroy(); }
};

#endif//HOMING_MISSLE_H
