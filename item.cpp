#include "item.h"

Item::Item()
{
    setX(POS_DEFAULT);
    setY(POS_DEFAULT);
    setZ(POS_DEFAULT);
    setLength(SIZE_DEFAULT);
    setWidth(SIZE_DEFAULT);
    setHeight(SIZE_DEFAULT);
}

Item::~Item(){
}

Item::Item(const double x, const double y,
                     const double z, const double length, const double width,
                     const double height) {
    setX(x);
    setY(y);
    setZ(z);
    setLength(length);
    setWidth(width);
    setHeight(height);
}

Item::Item(const Item &furniture) {
    setX(furniture.getX());
    setY(furniture.getY());
    setZ(furniture.getZ());
    setLength(furniture.getLength());
    setWidth(furniture.getWidth());
    setHeight(furniture.getHeight());
}

double Item::getX() const {
    return x_;
}

void Item::setX(const double x) {
    if(x>=0)
        x_=x;
    else
        x_=POS_DEFAULT;
}

double Item::getY() const {
    return y_;
}

void Item::setY(const double y) {
    if(y>=0)
        y_=y;
    else
        y_=POS_DEFAULT;
}

double Item::getZ() const {
    return z_;
}

void Item::setZ(const double z) {
    if(z>=0)
        z_=z;
    else
        z_=POS_DEFAULT;
}

double Item::getLength() const {
    return length_;
}

void Item::setLength(const double length) {
    if(length>0)
        length_=length;
    else
        length_=SIZE_DEFAULT;
}

double Item::getWidth() const {
    return width_;
}

void Item::setWidth(const double width) {
    if(width>0)
        width_=width;
    else
        width_=SIZE_DEFAULT;
}

double Item::getHeight() const {
    return height_;
}

void Item::setHeight(const double height) {
    if(height>0)
        height_=height;
    else
        height_=SIZE_DEFAULT;
}

string Item::getType() const {
    return "Item";
}

void Item::setInformation(const string info){ string s = info; }
string Item::getInformation() const { return ""; }
