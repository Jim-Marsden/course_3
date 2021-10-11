/*
* Vending Machine Project
* CSE-40477
*
* Product.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
using std::strcpy;

#include "Product.h"

Project1::Product::Product(const char *brand, const char *name,
    const char *size)
{
    strcpy(this->brand, brand);
    strcpy(this->name, name);
    strcpy(this->size, size);

    // TODO: Implement
}

const char *
Project1::Product::getBrand() const
{
    // TODO: Implement
    return brand;
}

void
Project1::Product::setBrand(const char *value)
{
    strcpy(brand, value);
    // TODO: Implement
}

const char *
Project1::Product::getName() const
{
    // TODO: Implement
    return name;
}

void
Project1::Product::setName(const char *value)
{
    strcpy(name, value);
    // TODO: Implement
}

const char *
Project1::Product::getSize() const
{
    // TODO: Implement
    return size;
}

void
Project1::Product::setSize(const char *value)
{
    strcpy(size, value);
    // TODO: Implement
}
