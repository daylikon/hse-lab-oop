#ifndef FURNITURE_H
#define FURNITURE_H
#include <string>
#include <item.h>

using namespace std;

class Furniture : public Item
{
public:
    // —татические переменные по умолчанию
    static constexpr const char* MATERIAL_DEFAULT = "Wood";
    Furniture(); // конструктор инициализации
    virtual ~Furniture();
    Furniture(const string material, const double x, const double y,
              const double z, const double length, const double width,
              const double height); // конструктор по умолчанию
    Furniture(const Furniture &furniture); // конструктор копировани€
    // —електоры и модификаторы
    virtual void setInformation(const string info);
    virtual string getInformation() const;
    virtual string getType() const;
private:
    string material_;
};

#endif // FURNITURE_H
