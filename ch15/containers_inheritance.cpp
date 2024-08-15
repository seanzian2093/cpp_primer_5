#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "quote.hpp"
// We cannot put objects of types related by inheritance directly into a container
    // - because there is no way to define a container that holds elements of differing types
    // - we can define the container to hold pointers/smart pointers preferably to base class
        // - dynamic type of the underlying objects must be base-class type or derived type from that base

int main()
{
    vector<Quote> basket;
    basket.push_back(Quote("0-201-82470-1", 50));
    // ok - but copies only the Quote part of the Bulk_quote object into basket
    basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, 0.25));
    // print net_price, which is 15* 50, not the one in Bulk_quote 15 * 50 * (1 - 0.25)
    cout << basket.back().net_price(15) << endl;

    vector<shared_ptr<Quote>> basket_ptr;
    basket_ptr.push_back(make_shared<Quote>("0-201-82470-1", 50));
    basket_ptr.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 10, 0.25));
    // print net_price defined by Bulk_quote 15 * 50 * (1 - 0.25)
    cout << basket_ptr.back()->net_price(15) << endl;
    return 0;
}