#ifndef COLLECTION_H
#define COLLECTION_H
#include "furniture.h"
#include "item.h"
#include "tech.h"

class Collection
{
public:
    Collection(); // конструктор по умолчанию
    Collection(const Collection &ccol);
    ~Collection();
    void add(const string material, const double x, const double y,
             const double z, const double length, const double width,
             const double height, const string type);
    void addCabinet(Furniture &cab);
    void addTech(Tech &tech);
    Item* get(const int n); // метод доступа к элементу по индексу
    void del(const int n); // метод удаления элемента
    void clearall(); // метод удаления всех элементов
    int getLength() const; // метод возвращающий кол-во объектов
    void toFile(string filename) const; // экспорт в файл
    void fromFile(string filename); // импорт из файла
    int checkFurniture(); // метод проверки пересечения мебели и техники
private:
    int n_;
    Item *collection_[];
};

#endif // COLLECTION_H
