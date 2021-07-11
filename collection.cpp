#include "collection.h"
#include "furniture.h"
#include "item.h"
#include "tech.h"
#include <iostream>
#include <fstream>

Collection::Collection()
{
    n_ = 0;
    Item *collection_[] = { new Item, new Furniture, new Tech};
}
void Collection::add(const string info, const double x, const double y,
         const double z, const double length, const double width,
                     const double height, const string type){
    if(type == "Tech"){
        collection_[n_] = new Tech();
    } else if (type == "Furniture") {
        collection_[n_] = new Furniture();
    } else {
        collection_[n_] = new Item();
    }
    collection_[n_]->setX(x);
    collection_[n_]->setY(y);
    collection_[n_]->setZ(z);
    collection_[n_]->setLength(length);
    collection_[n_]->setWidth(width);
    collection_[n_]->setHeight(height);
    collection_[n_]->setInformation(info);
    n_++;
}
void Collection::addCabinet(Furniture &cab){
    this->n_++;
    collection_[n_-1] = &cab;
}

void Collection::addTech(Tech &tech){
    this->n_++;
    collection_[n_-1] = &tech;
}

Item* Collection::get(const int n) {
    return collection_[n];
}

Collection::Collection(const Collection &ccol) {
    this->n_=ccol.n_;
    for(int i=0; i<n_;i++){
        this->collection_[i]=ccol.collection_[i];
    }
}

Collection::~Collection() {

}

void Collection::del(const int n){
    delete collection_[n];
    for(int i=n;i<n_-1;i++){
        collection_[i]=collection_[i+1];
    }
    cout << "H" << collection_[n]->getInformation() << endl;
    n_--;
    cout << "L" << getLength() << endl;
}

void Collection::clearall(){
    for(int i=0;i<n_;i++){
        delete collection_[i];
    }
    this->n_=0;
}

int Collection::getLength() const {
    return n_;
}

void Collection::toFile(string filename) const {
    fstream s(filename, s.binary | s.trunc | s.out);
    if (!s.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        s << n_ << endl;
        for(int i=0;i<n_;i++) {
            s << collection_[i]->getType() << " "
              << collection_[i]->getX() << " "
              << collection_[i]->getY() << " "
              << collection_[i]->getZ() << " "
              << collection_[i]->getWidth() << " "
              << collection_[i]->getLength() << " "
              << collection_[i]->getHeight() << " "
              << collection_[i]->getInformation() << endl;
        }
        s.close();
    }
}

void Collection::fromFile(string filename) {
    fstream s(filename, s.binary | s.in);
    if (!s.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        for(int i=0; i<n_;i++){
            delete collection_[i];
        }
        n_=0;
        s >> this->n_;
        double x,y,z,width,length,height;
        string type,info;
        for(int i=0;i<n_;i++) {
            s >> type >> x >> y >> z >> width >> length >> height >> info;
            if(type == "Furniture"){
                collection_[i] = new Furniture;
                collection_[i]->setX(x);
                collection_[i]->setY(y);
                collection_[i]->setZ(z);
                collection_[i]->setWidth(width);
                collection_[i]->setLength(length);
                collection_[i]->setHeight(height);
                collection_[i]->setInformation(info);
            } else if(type == "Tech"){
                collection_[i] = new Tech;
                collection_[i]->setX(x);
                collection_[i]->setY(y);
                collection_[i]->setZ(z);
                collection_[i]->setWidth(width);
                collection_[i]->setLength(length);
                collection_[i]->setHeight(height);
                collection_[i]->setInformation(info);
            }
        }
        s.close();
    }
}

int checkPos(double pos1, double pos2, double len1, double len2, string mat1, string mat2){
    int delta=0;
    if(mat1!=mat2){
        delta=2;
    }
    if(pos1>pos2){
        if(pos2+len2+delta>pos1){
            return 0;
        }
    }
    else if(pos1+len1+delta>pos2) {
            return 0;
    }
    return 1;
}

int Collection::checkFurniture() {
    int result = 1;
    for(int i=0;i<n_-1;i++){
        for(int j=i+1;j<n_;j++){
            if(collection_[i]->getType() == "Furniture" && collection_[j]->getType() == "Furniture"){
                int pres=0;
                pres+=checkPos(collection_[i]->getX(), collection_[j]->getX(),
                               collection_[i]->getLength(),
                               collection_[j]->getLength(),
                               collection_[i]->getInformation(),
                               collection_[j]->getInformation());
                pres+=checkPos(collection_[i]->getY(), collection_[j]->getY(),
                               collection_[i]->getWidth(),
                               collection_[j]->getWidth(),
                               collection_[i]->getInformation(),
                               collection_[j]->getInformation());
                pres+=checkPos(collection_[i]->getZ(), collection_[j]->getZ(),
                               collection_[i]->getHeight(),
                               collection_[j]->getHeight(),
                               collection_[i]->getInformation(),
                               collection_[j]->getInformation());
                if(pres==0){
                    result = 0;
                }
            }
        }
    }
    return result;
}
