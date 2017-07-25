#include<iostream>
#include<map>
#include<set>
#include<iterator>
#include<string>

/*************************************************************
structure to store bid and offer details.
*************************************************************/
struct bidorder
{
public:
	int price;
	std::string sbidorder;
        int bidoroffer;
};


/*************************************************************
compartor to sort bid details in map
*************************************************************/
struct comparebid
{
	bool operator()(const bidorder &lhs, const bidorder &rhs) const
	{
		return lhs.price < rhs.price ;
	}
};

/*************************************************************
compartor to sort offer details in map
*************************************************************/
struct compareorder
{
	bool operator()(const bidorder &lhs, const bidorder &rhs) const
	{
		return lhs.price > rhs.price;
	}
};


/*************************************************************
Orderbook class to store both bid and offer details
*************************************************************/
class OrderBook
{
//private:
protected:
	std::multiset<bidorder, compareorder > m_vOrders;
	std::multiset<bidorder, comparebid > m_vBids;
	std::map<std::string, int> m_mAllOrders;
public:
	bool AddBids(bidorder bid);
	bool AddOrder(bidorder order);
	bool deleteOrder(std::string bidorder);
	int GetOrderBookSize();
        int GetOrderSize(); 
        int GetBidSize();
        void printBids(std::string sproduct);
        void printOrders(std::string sproduct);
};


class MarketPrices
{
public:
       /************************************************************************************************
        *** This function is called to enter new bid or offer in the system,
        *** The order has to be stored in the correct position of the orderbook according to the sort order
        *** ProductId uniquely identifies the product on which the order is entered.
        *** OrderId uniquely identifies the order.
        *** BidOrOffer indicates whether the order is a bid or offer.
        *** 1 indicated it's a bid
        *** 2 indicated it's a offer
        *** return 0 in case of any error.   
        *************************************************************************************************/
        
	virtual int OnOrderAdd(char *ProductId, char * OrderId, int BidOrOffer, int Price ) = 0;
	virtual int OnOrderDel(char *ProductId, char *OrderId)=0;
	virtual int Print()=0;
};

class StockPrices : public MarketPrices
{
public:
	virtual int OnOrderAdd(char *ProductId, char * OrderId, int BidOrOffer, int Price);
	virtual int OnOrderDel(char *ProductId, char *OrderId);
	int Print();
private:
	std::map<std::string, OrderBook> m_mOrderBook;
};
