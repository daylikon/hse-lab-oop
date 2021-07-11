#ifndef TECH_H
#define TECH_H
#include <string>
#include <item.h>

class Tech : public Item
{
public:
    static constexpr const char* NAME_DEFAULT = "NoName";
    Tech();
    virtual ~Tech();
    Tech(const Tech &tech);
    Tech(const string name, const double x, const double y,
         const double z, const double length, const double width,
         const double height);
    virtual void setInformation(const string info);
    virtual string getInformation() const;
    virtual string getType() const;
private:
    string name_;
};

#endif // TECH_H
