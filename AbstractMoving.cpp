#include "AbstractMoving.h"



// Movable adapter
MovableAdp::MovableAdp(UObject* setObj)
{
    movableObj = setObj;
}



Vector MovableAdp::getPosition()
{
    return std::any_cast<Vector>(movableObj->getProperty("position"));
}



Vector MovableAdp::getVelocity()
{
    int d = std::any_cast<int>(movableObj->getProperty("direction"));
    int n = std::any_cast<int>(movableObj->getProperty("directionsNumber"));
    int v = std::any_cast<int>(movableObj->getProperty("velocity"));

    return Vector(v * cos((double)d / 360 * n), v * sin((double)d / 360 * n));
}



void MovableAdp::setPosition(Vector newV)
{
    movableObj->setProperty("position", newV);
}



// MovingObj class
MovingObj::MovingObj(MovableAdp setMove)
{
    moveObj = setMove;
}



void MovingObj::execute()
{
    int newPosX = moveObj.getPosition().first +
                  moveObj.getVelocity().first;

    int newPosY = moveObj.getPosition().second +
                  moveObj.getVelocity().second;

    moveObj.setPosition(Vector(newPosX, newPosY));
}



// Rotatable adapter
RotatableAdp::RotatableAdp(UObject* setObj)
{
    rotatableObj = setObj;
}



int RotatableAdp::getDirection()
{
    return std::any_cast<int>(rotatableObj->getProperty("direction"));
}



int RotatableAdp::getAngularVelocity()
{
    return std::any_cast<int>(rotatableObj->getProperty("angularVelocity"));
}



void RotatableAdp::setDirection(int newV)
{
    rotatableObj->setProperty("direction", newV);
}



int RotatableAdp::getDirectionsNumber()
{
    return std::any_cast<int>(rotatableObj->getProperty("directionsNumber"));
}



// RotatingObj class
RotatingObj::RotatingObj(RotatableAdp setRotate)
{
    rotateObj = setRotate;
}



void RotatingObj::execute()
{
    int newDirection = rotateObj.getDirection() + rotateObj.getAngularVelocity();

    rotateObj.setDirection(newDirection);
}



Spaceship::Spaceship(std::map<std::string, std::any> beginCond)
{
    for (std::map<std::string, std::any>::iterator iter = beginCond.begin();
        iter != beginCond.end();
        iter++)
    {
        std::string key = iter->first;
        spaceshipData[key] = iter->second;
    }
}



std::any Spaceship::getProperty(std::string key)
{
    return spaceshipData[key];
}



void     Spaceship::setProperty(std::string key, std::any newValue)
{
    spaceshipData[key] = newValue;
}