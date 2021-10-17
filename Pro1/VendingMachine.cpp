/*
* Vending Machine Project
* CSE-40477
*
* VendingMachine.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "VendingMachine.h"

#include <algorithm>
#include <numeric>

Project1::VendingMachine::VendingMachine(
        ostream &statusPanelStream,
        const char *productNames[NUM_PRODUCT_RACKS],
        unsigned productPrices[NUM_PRODUCT_RACKS])
        : statusPanel(statusPanelStream),
          deliveryChute(statusPanel),
          numCoins(0),
          unspentMoneyCents(0) {

    for (auto &coin: coinBox) { coin = nullptr; }
    for (int i = 0; i < NUM_PRODUCT_RACKS; ++i) {
        this->productRacks[i] = new ProductRack(statusPanel, productNames[i], deliveryChute, productPrices[i]);
        this->productButtons[i] = new ProductButton(*this->productRacks[i]);
    }
    //for(auto & product_rack : productRacks) product_rack = nullptr;
//    for (auto &buttons: productButtons) buttons = nullptr;
    // TODO: Implement
}

Project1::VendingMachine::~VendingMachine() {
    for (auto &coin: coinBox) delete coin;
    for (auto &buttons: productButtons) delete buttons;
    for (auto &product_rack: productRacks) delete product_rack;
    // TODO: Implement
}

bool
Project1::VendingMachine::insertCoin(Coin *pCoin) {
    if (pCoin) {
        if (pCoin->getDenomination() == Coin::COINTYPE_WOODEN_NICKEL) {
            statusPanel.displayMessage(StatusPanel::MESSAGECODE_BAD_COIN);
            return false;
        }
        unspentMoneyCents += pCoin->getValueCents();
        coinBox[numCoins] = pCoin;
        numCoins++;
        return true;
    }
    // TODO: Implement
    return false;
}

bool
Project1::VendingMachine::pressButton(int button) {
//    return false;
    if (button < 0 || button > NUM_PRODUCT_RACKS) {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_WRONG_BUTTON);
        return false;
    }
    if (productRacks[button]->getProductPriceCents() <= unspentMoneyCents) {
        return productRacks[button]->deliverProduct();
        unspentMoneyCents = 0;
    } else {
        statusPanel.displayMessage(StatusPanel::MESSAGECODE_INSUFFICIENT_MONEY);
        return false;
    }
    // TODO: Implement
    return false;
}

Project1::Product *
Project1::VendingMachine::retrieveProduct() {
    // TODO: Implement
    return deliveryChute.retrieveProduct();
}

bool
Project1::VendingMachine::addProduct(Product *pProduct) {
    for (auto &rack: productRacks) {
        if (rack->isCompatibleProduct(pProduct->getName())) {
            return rack->addProduct(pProduct);
        }
    }
    // TODO: Implement
    statusPanel.displayMessage(StatusPanel::MESSAGECODE_NO_RACK_FOR_PRODUCT);
    return false;
}

unsigned
Project1::VendingMachine::getProductCount(const char *productName) const {
    // TODO: Implement
    for (auto &rack: productRacks) {
        if(rack->isCompatibleProduct(productName)) {
            return rack->getNumProductsInRack();
        }
    }
    return 0;
}

unsigned
Project1::VendingMachine::countTill() const {
    auto result{0ul};
    for (auto &e: coinBox) if (e != nullptr) result += e->getValueCents();
    return result;
//    // TODO: Implement
//    return std::accumulate(std::cbegin(coinBox), std::cend(coinBox), 0);
}

unsigned
Project1::VendingMachine::getNumCoinsInCoinBox() const {
    // TODO: Implement
    return numCoins;
}
