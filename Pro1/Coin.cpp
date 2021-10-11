/*
* Vending Machine Project
* CSE-40477
*
* Coin.cpp
* YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
*/
#include "Coin.h"

Project1::Coin::Coin(CoinType denomination)
    : denomination(denomination)
{
    // TODO: Implement
}

Project1::Coin::CoinType
Project1::Coin::getDenomination() const
{
    return denomination;
}

unsigned
Project1::Coin::getValueCents() const
{
    switch(denomination){
        case COINTYPE_PENNY: return 1;
        case COINTYPE_NICKEL: return 5;
        case COINTYPE_DIME: return 10;
        case COINTYPE_QUARTER: return 25;
        case COINTYPE_HALF_DOLLAR: return 50;
        case COINTYPE_DOLLAR: return 100;
        case COINTYPE_WOODEN_NICKEL:
        default: return 0;
    }
    return 0;
}
