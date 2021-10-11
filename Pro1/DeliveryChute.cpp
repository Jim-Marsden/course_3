/*
* Vending Machine Project
* CSE-40477
*
* DeliveryChute.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "DeliveryChute.h"

Project1::DeliveryChute::DeliveryChute(StatusPanel &statusPanel)
    : statusPanel(statusPanel),
      pProduct(nullptr)
{
    // TODO: Implement
}

Project1::DeliveryChute::~DeliveryChute()
{
    delete pProduct;
//    if(pProduct)delete pProduct;
    // TODO: Implement
}

bool
Project1::DeliveryChute::insertProduct(Product *pProduct)
{
    if(!this->pProduct){
        this->pProduct = pProduct;
        return true;
    }
    statusPanel.displayMessage(StatusPanel::MESSAGECODE_CHUTE_FULL);
    // TODO: Implement
    return false;
}

Project1::Product *
Project1::DeliveryChute::retrieveProduct()
{
    // TODO: Implement
    if(pProduct != nullptr) {
        auto temp = pProduct;
        pProduct = nullptr;
        return temp;
    }
    else return nullptr;
}

bool
Project1::DeliveryChute::containsProduct() const
{
    // TODO: Implement
    return pProduct != nullptr;
}