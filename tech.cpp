#include "tech.h"
#include <string>
#include <iostream>
#include <item.h>

Tech::Tech()
{
    setInformation(NAME_DEFAULT);
}

Tech::~Tech()
{
}

Tech::Tech(const string name, const double x, const double y,
                     const double z, const double length, const double width,
                     const double height) : Item(x, y, z, length, width, height){
    setInformation(name);
    setX(x);
    setY(y);
    setZ(z);
    setLength(length);
    setWidth(width);
    setHeight(height);
}

Tech::Tech(const Tech &tech) {
    setInformation(tech.getInformation());
    setX(tech.getX());
    setY(tech.getY());
    setZ(tech.getZ());
    setLength(tech.getLength());
    setWidth(tech.getWidth());
    setHeight(tech.getHeight());
}

string Tech::getInformation() const{
    return name_;
}

void Tech::setInformation(const string info) {
    name_=info;
}

string Tech::getType() const {
    return "Tech";
}
