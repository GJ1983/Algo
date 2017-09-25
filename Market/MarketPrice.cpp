#include "MarketPrice.h"
#include<algorithm>
#include<cstring>
#include<string>

int BidOrOfferContainer::AddOrder(char *OrderId, int bidOrOffer, int Price)
{
	if( !OrderId )
		return 1;

	Order oder;
	oder.OrderId = OrderId;
	oder.Price = Price;

	switch (bidOrOffer)
	{
		case BidOrOffer::Bid:
		{
			std::list<Order>::iterator itrPos = std::find_if(m_bids.begin(), m_bids.end(), [OrderId](const Order& order)
			{
			   return (strcmp(order.OrderId.c_str(), OrderId) == 0);
			}); 
		        if (itrPos != m_bids.end())
	       	        {  
			   return 1;
			}

		        std::list<Order>::iterator itrInsertPos = std::find_if(m_bids.begin(), m_bids.end(), [Price](const Order& order)
		        {
			   return order.Price < Price;
		        });
			if (itrInsertPos != m_bids.end())
			{
			   m_bids.insert(itrInsertPos, oder);
			}
			else
			{
			   m_bids.push_back(oder);
			}

		}
               break;
               case BidOrOffer::Offer:
               {
		       //Check if already exsists
		       std::list<Order>::iterator itrPos = std::find_if(m_offers.begin(), m_offers.end(), [OrderId](const Order& order)
		       {
			 return (strcmp(order.OrderId.c_str(), OrderId) == 0);
		       });
		       if (itrPos != m_offers.end())
		       {
			 return 1;
		       }

		       std::list<Order>::iterator itrInsertPos = std::find_if(m_offers.begin(), m_offers.end(), [Price](const Order& order){return order.Price > Price; });
		       if (itrInsertPos != m_offers.end())
		       {
			 m_offers.insert(itrInsertPos, oder);
		       }
		       else
		       {
			 m_offers.push_back(oder);
		       }
                }
                        break;
	}
	return 0;

}

int BidOrOfferContainer::DeleteOrder(char *OrderId)
{
	std::list<Order>::iterator itrPos = std::find_if(m_bids.begin(), m_bids.end(), [OrderId](const Order& order)
	{
		return (strcmp(order.OrderId.c_str(), OrderId) == 0);
	});
	if (itrPos != m_bids.end())
	{
		m_bids.remove(*itrPos);
		return 0;
	}

	itrPos = std::find_if(m_offers.begin(), m_offers.end(), [OrderId](const Order& order)
	{
		return (strcmp(order.OrderId.c_str(), OrderId) == 0);
	});
	if (itrPos != m_offers.end())
	{
		m_offers.remove(*itrPos);
		return 0;
	}
	return 1;
}

int BidOrOfferContainer::Print()
{
        std::cout << "Buy:" << std::endl;
        for (auto itr : m_bids)
        {
                std::cout << itr.OrderId.c_str() << "\t" << itr.Price << std::endl;
        }
        std::cout << "Sell:" << std::endl;
        for (auto itr : m_offers)
        {
                std::cout << itr.OrderId.c_str() << "\t" << itr.Price << std::endl;
        }
        return 0;
}



int StockPrice::OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) 
{
	if( !productId || !OrderId )
		return 1;

	std::map<std::string, BidOrOfferContainer*>::iterator itr = m_orderBooks.find(productId);

	if (itr != m_orderBooks.end())
	{
		return itr->second->AddOrder(OrderId, BidOrOffer, Price);
	}
	else
	{
		BidOrOfferContainer* orders = new BidOrOfferContainer();
		m_orderBooks[productId] = orders;
		return orders->AddOrder(OrderId, BidOrOffer, Price);
	}

	return 0;
}

int StockPrice::OnOrderDel(char *productId, char *OrderId)
{
        return m_orderBooks[productId]->DeleteOrder(OrderId);
}

int StockPrice::Print()
{
	for (auto itr : m_orderBooks)
        {
                std::cout << itr.first.c_str() << std::endl;
                (itr.second)->Print();
        }
        return 0;
}

StockPrice::~StockPrice()
{
        for (auto itr : m_orderBooks)
        {
                delete itr.second;
                itr.second = nullptr;
        }
        m_orderBooks.clear();
}

MarketPrices::~MarketPrices()
{

}



/*int main()
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

	*** As I don't have visual studio, So I wrote programe on ubuntu using vi editor, So I was not having any unit test framework
	**** Although I can install googletest,, but As I need to sent ot over email, So I didn't install, So the unit tests scnenarios I can think of are as below.

	**** 1. Check for missing productId
	**** 2. Check for missing OrderId
	**** 3. Check for trying to insert same record, with same productId , OrderId 
	**** 4. deletion of a Product
	**** 5. deletion of an order
	**** 6. test of print function ****


	return 0;
} **/
