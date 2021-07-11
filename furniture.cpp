#include "furniture.h"
#include <string>
#include <iostream>
#include <item.h>

Furniture::Furniture() : Item() {
    setInformation(MATERIAL_DEFAULT);
}

Furniture::~Furniture(){
}

Furniture::Furniture(const string material, const double x, const double y,
                     const double z, const double length, const double width,
                     const double height) : Item(x, y, z, length, width, height){
    setInformation(material);
    setX(x);
    setY(y);
    setZ(z);
    setLength(length);
    setWidth(width);
    setHeight(height);
}

Furniture::Furniture(const Furniture &furniture) {
    setInformation(furniture.getInformation());
    setX(furniture.getX());
    setY(furniture.getY());
    setZ(furniture.getZ());
    setLength(furniture.getLength());
    setWidth(furniture.getWidth());
    setHeight(furniture.getHeight());
}

string Furniture::getInformation() const{
    return material_;
}

void Furniture::setInformation(const string info) {
    material_=info;
}

string Furniture::getType() const {
    return "Furniture";
}
