/*
* Vending Machine Project
* CSE-40477
*
* ProductRack.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include <cstring>
#include <iostream>

using std::strcmp;

#include "ProductRack.h"

Project1::ProductRack::ProductRack(
        StatusPanel &statusPanel,
        const char *allowedProductName,
        DeliveryChute &deliveryChute,
        unsigned productPriceCents)
        : statusPanel(statusPanel),
          deliveryChute(deliveryChute),
          productCount(0),
          productPriceCents(productPriceCents) {
    strcpy(this->allowedProductName, allowedProductName);
    for (auto &x: products) x = nullptr;
    // TODO: Implement
}

Project1::ProductRack::~ProductRack() {

    // TODO: Implement
}

bool
Project1::ProductRack::isCompatibleProduct(const char *productName) const {
    // TODO: Implement
    return strcmp(productName, allowedProductName) == 0;
}

bool
Project1::ProductRack::isFull() const {
    // TODO: Implement
    return productCount < MAX_PRODUCTS;
}

bool
Project1::ProductRack::isEmpty() const {
    // TODO: Implement
    return productCount < 0;
}

bool
Project1::ProductRack::addProduct(Product *pProduct) {
    if (!pProduct) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_ERRORS_END);
    }

    if (strcmp(allowedProductName, pProduct->getName())) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_PRODUCT_DOES_NOT_MATCH_PRODUCT_RACK);
        return false;
    }
    if (productCount >= MAX_PRODUCTS) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_RACK_IS_FULL);
        return false;
    }

    this->products[productCount] = pProduct;
    productCount++;

    // TODO: Implement
    return true;
}

bool
Project1::ProductRack::deliverProduct() {

    if (productCount < MAX_PRODUCTS && productCount >= 1) {
        if (deliveryChute.insertProduct(products[productCount - 1])) {
            products[productCount - 1] = nullptr;
            productCount--;
            return true;
        }
    }
    // TODO: Implement
    return false;
}

unsigned
Project1::ProductRack::getNumProductsInRack() const {
    // TODO: Implement
    return productCount;
}

unsigned
Project1::ProductRack::getProductPriceCents() const {
    // TODO: Implement
    return productPriceCents;
}
