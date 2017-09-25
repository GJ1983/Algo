#include<iostream>
#include<map>
#include<set>
#include<iterator>
#include<string>

#include "MarketPrice.h"



bool OrderBook::AddBids(bidorder bid)
{
	std::map<std::string, int>::iterator ite = m_mAllOrders.find(bid.sbidorder);
	//if(ite != m_mAllOrders.end() )
	if(ite == m_mAllOrders.end() )
	{
		m_mAllOrders[bid.sbidorder] = bid.price;
		m_vBids.insert(bid);
		return true;
	}
	return false;
}

bool OrderBook::AddOrder(bidorder bid)
{
	std::map<std::string, int>::iterator ite = m_mAllOrders.find(bid.sbidorder);
	if(ite == m_mAllOrders.end() )
	{
		m_mAllOrders[bid.sbidorder] = bid.price;
		m_vOrders.insert(bid);
		return true;
	}
	return false;
}

bool OrderBook::deleteOrder(std::string bidorOrder)
{
	std::map<std::string, int>::iterator ite = m_mAllOrders.find(bidorOrder);

	if(ite == m_mAllOrders.end() )
	{
		return false; 
	}

	bidorder obj;
	obj.price = ite->second;
	obj.sbidorder = ite->first;

	if(m_vOrders.find(obj) != m_vOrders.end() ) 
	{
		m_vOrders.erase(obj);
	}
	else if(m_vBids.find(obj) != m_vBids.end() )
	{
		m_vBids.erase(obj);
	}
	else
	{
		return false;
	}
	return true;
}

int OrderBook::GetOrderBookSize()
{
	return m_mAllOrders.size();
}

int OrderBook::GetOrderSize()
{
	return m_vOrders.size();
}

int OrderBook::GetBidSize()
{
	return m_vBids.size();
}

void OrderBook::printBids(std::string sproduct )
{
	std::cout<<sproduct <<" :\n";
	//std::cout<<"Buy:\n";
        int i = 0;
	for(std::multiset<bidorder>::iterator ite = m_vBids.begin(); ite != m_vBids.end() ; ite++)
	{
                if( ite->bidoroffer == 1 && i == 0)
                {
			std::cout<<"Buy:\n";
                        i++;
                }
		//std::cout<<ite->sbidorder << " "<<ite->price;
                //std::cout<<std::endl; 
                if( ite->bidoroffer == 2 && (i == 0 || i == 1 ))
                {
			std::cout<<"Sell:\n";
                        i++;
                }
		std::cout<<ite->sbidorder << " "<<ite->price;
                std::cout<<std::endl; 
	}
}

void OrderBook::printOrders(std::string sproduct )
{
	std::cout<<sproduct <<" :\n";
	std::cout<<"Sell:\n";
	for(std::multiset<bidorder>::iterator ite = m_vOrders.begin(); ite != m_vOrders.end() ; ite++)
	{
		//std::cout<<sproduct <<" :\n";
		//std::cout<<"Sell:\n";
		std::cout<<ite->sbidorder << " "<<ite->price;
                std::cout<<std::endl; 
	}
}

int StockPrices::OnOrderAdd(char *ProductId, char * OrderId, int BidOrOffer, int Price)
{
	if(!ProductId || !OrderId)
		return 0;

	std::map<std::string, OrderBook>::iterator ite = m_mOrderBook.find(ProductId);

	if(ite != m_mOrderBook.end() )
	{
		OrderBook & orderbook = ite->second;
		bidorder obj;
		obj.price = Price;
		obj.sbidorder = OrderId;
		if( BidOrOffer == 1)
		{
			//m_mOrderBook.insert(std::make_pair(ProductId,orderbook)); 
			orderbook.AddBids(obj);
			//return orderbook.AddBids(obj);
		}
		else
		{
			orderbook.AddOrder(obj);	
			//m_mOrderBook.insert(std::make_pair(ProductId,orderbook)); 
			//return orderbook.AddOrder(obj);	
		}
	}
        else
	{
		OrderBook orderbook;
		bidorder obj;
		obj.price = Price;
		obj.sbidorder = OrderId;
		if( BidOrOffer == 1)
		{
                        obj.bidoroffer = 1;
			orderbook.AddBids(obj);
			m_mOrderBook.insert(std::make_pair(ProductId,orderbook)); 
			//return orderbook.AddBids(obj);
		}
		else
		{
                        obj.bidoroffer = 2;
			orderbook.AddOrder(obj);	
			m_mOrderBook.insert(std::make_pair(ProductId,orderbook)); 
			//return orderbook.AddOrder(obj);	
                }
   
	}
}

int StockPrices::OnOrderDel(char *ProductId, char *OrderId)
{
	if(!ProductId || !OrderId )
		return 0;

	std::map<std::string, OrderBook>::iterator ite = m_mOrderBook.find(ProductId) ;

	if(ite != m_mOrderBook.end() )
	{
		OrderBook &orderbook = ite->second;
		orderbook.deleteOrder(OrderId);
	}
	}


int StockPrices::Print()
{
	for(std::map<std::string, OrderBook>::iterator ite = m_mOrderBook.begin(); ite != m_mOrderBook.end(); ++ite)
	{
		//OrderBook &orderbook = ite->second;
		OrderBook orderbook = ite->second;
		orderbook.printBids(ite->first);
		//orderbook.printOrders(ite->first);
	}
}


int main()
{
	StockPrices *sprice = new StockPrices();
	sprice->OnOrderAdd("product1","order1", 1, 100);
	sprice->OnOrderAdd("product1","order2", 2, 101);
	sprice->OnOrderAdd("product3","order3", 1, 99);
	sprice->OnOrderAdd("product3","order4", 2, 98);
	sprice->OnOrderAdd("product4","order5", 2, 62);
        sprice->Print();
	return 0;
}
