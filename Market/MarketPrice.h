#include<list>
#include<map>
#include<iostream>
#include<string>


enum BidOrOffer
{
        Bid = 1,
        Offer = 2
};

struct Order
{
        std::string OrderId;
        double Price;
        bool operator==(const Order& order1)
        {
                return (OrderId == order1.OrderId);
        }
};



class BidOrOfferContainer
{
public:
        int AddOrder(char *OrderId, int BidOrOffer, int Price);
        int DeleteOrder(char *OrderId);
        int Print();
private:
        std::list<Order> m_bids;
        std::list<Order> m_offers;
};

class MarketPrices
{
public:
        /* This function is called to enter a new Bid or Offer in the system. The order has to be
        stored in the correct position of the orderbook according to the sort order
        ProductId uniquely identifies the product on which the order is entered.
        OrderId uniquely identifies the order
        BidOrOffer indicates whether the order is a bid or an offer. 1 indicates it is a Bid,
        2 otherwise
        Returns 0 in case of errors */
        virtual int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) = 0;


        /* This function is called to delete an existing order present in the orderbook.
        ProductId uniquely identifies the product on which the order is entered.
        OrderId uniquely identifies the order to be deleted
        Returns 0 in case of errors */
        virtual int OnOrderDel(char *productId, char *OrderId) = 0;


        /* This function is called to print all the bid and offer orders present in the orderbook for all
        products.
        Returns 0 in case of errors */
        virtual int Print() = 0;

        virtual ~MarketPrices() = 0;
};



class StockPrice : public MarketPrices
{
public:
        int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price);
        int OnOrderDel(char *productId, char *OrderId);
        int Print();
        ~StockPrice();
private:
        std::map<std::string, BidOrOfferContainer*> m_orderBooks;
};


