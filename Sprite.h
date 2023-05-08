#pragma once
#include "GameObject.h"
class Sprite :
    public GameObject
{
public:
    Sprite(std::string objectName = "Sprite") : GameObject(objectName)
    {}

    ~Sprite();
};

