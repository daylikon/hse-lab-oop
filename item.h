#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item
{
public:
    static constexpr const double POS_DEFAULT = 0;
    static constexpr const double SIZE_DEFAULT = 1;
    Item();
    virtual ~Item();
    Item(const double x, const double y,
              const double z, const double length, const double width,
              const double height); // конструктор по умолчанию
    Item(const Item &item);
    double getX() const;
    void setX(const double x);
    double getY() const;
    void setY(const double y);
    double getZ() const;
    void setZ(const double z);
    double getLength() const;
    void setLength(const double length);
    double getWidth() const;
    void setWidth(const double width);
    double getHeight() const;
    void setHeight(const double height);
    virtual void setInformation(const string info);
    virtual string getInformation() const;
    virtual string getType() const;
private:
    double x_, y_, z_, length_, width_, height_;
};

#endif // ITEM_H
