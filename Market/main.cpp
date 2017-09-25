#include "MarketPrice.h"

int main()
{
        StockPrice mrktPrices;
        mrktPrices.OnOrderAdd("P1", "O1", 1, 100);
        mrktPrices.OnOrderAdd("P1", "O2", 1, 99);
        mrktPrices.OnOrderAdd("P1", "O4", 1, 200);
        mrktPrices.OnOrderAdd("P1", "O5", 1, 150);

        mrktPrices.OnOrderAdd("P1", "O1", 2, 100);
        mrktPrices.OnOrderAdd("P1", "O2", 2, 99);
        mrktPrices.OnOrderAdd("P1", "O3", 2, 80);
        mrktPrices.OnOrderAdd("P1", "O5", 2, 150);
        mrktPrices.OnOrderAdd("P1", "O7", 2, 1);


        mrktPrices.OnOrderAdd("P2", "O1", 1, 1000);
        mrktPrices.OnOrderAdd("P2", "O3", 2, 12);
        mrktPrices.OnOrderAdd("P2", "O4", 2, 2);

        mrktPrices.OnOrderAdd("P3", "O1", 1, 200);
        mrktPrices.OnOrderAdd("P3", "O2", 1, 60);
        mrktPrices.OnOrderAdd("P3", "O3", 2, 1);
        mrktPrices.OnOrderAdd("P3", "O4", 2, 20);

        mrktPrices.Print();

        /*** As I don't have visual studio, So I wrote programe on ubuntu using vi editor, So I was not having any unit test framework
        **** Although I can install googletest,, but As I need to sent ot over email, So I didn't install, So the unit tests scnenarios I can think of are as below.

        **** 1. Check for missing productId
        **** 2. Check for missing OrderId
        **** 3. Check for trying to insert same record, with same productId , OrderId 
        **** 4. deletion of a Product
        **** 5. deletion of an order
        **** 6. test of print function ****/


        return 0;
}

