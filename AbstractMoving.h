#pragma once

#include <utility>
#include <any>
#include <map>
#include <string>
#include <cmath>

using Vector = std::pair<int, int>;



class UObject
{
public:
    virtual std::any getProperty(std::string key) = 0;
    virtual void     setProperty(std::string key, std::any newValue) = 0;
};



class Movable
{
    virtual Vector getPosition() = 0;
    virtual Vector getVelocity() = 0;
    virtual void setPosition(Vector newV) = 0;
};



class MovableAdp : public Movable
{
public:
    MovableAdp() {};
    MovableAdp(UObject* setObj);

    virtual Vector getPosition();
    virtual Vector getVelocity();
    virtual void setPosition(Vector newV);

private:
    UObject* movableObj = nullptr;
};



class MovingObj
{
public:
    MovingObj(MovableAdp setMove);
    void execute();

private:
    MovableAdp moveObj;
};



class Rotatable
{
public:
    virtual int getDirection() = 0;
    virtual int getAngularVelocity() = 0;
    virtual void setDirection(int newV) = 0;
    virtual int getDirectionsNumber() = 0;
};



class RotatableAdp : public Rotatable
{
public:
    RotatableAdp() {};
    RotatableAdp(UObject* setObj);

    virtual int getDirection();
    virtual int getAngularVelocity();
    virtual void setDirection(int newV);
    virtual int getDirectionsNumber();

private:
    UObject* rotatableObj = nullptr;
};



class RotatingObj
{
public:
    RotatingObj(RotatableAdp setRotate);
    void execute();

private:
    RotatableAdp rotateObj;
};



class Spaceship : public UObject
{
public:
    Spaceship(std::map<std::string, std::any> beginCond);

    virtual std::any getProperty(std::string key);
    virtual void     setProperty(std::string key, std::any newValue);

private:
    std::map<std::string, std::any> spaceshipData;
};