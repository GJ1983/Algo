#include<iostream>
#include<vector>
#include<string>
#include<map>

/**********************************Key Notes*****************************************************************
***** 1. F_Network class :-  containing information about road like roadid, name etc.
***** 2. F_Network_Collection :- Collection class containing infromation in memory.
*****                          using stl::map to store all data
*****                         As we know the size of the file upfront, we can use std::vector to improve performace
*****                         We can use hash table, if the data pattern changes like <co=3>, <re =15> etc. 
**********************************Key Notes*****************************************************************/

//class Key
//{
//public:
//        Key(long roaid)
//        {
//		RoadId = roaid;
//                LinkId = 0;
//        }
//	Key(long roadid, float linkid);
//        bool operator<(const Key &rhs) const
//        {
//		LinkId < rhs.LinkId;
//        }
//        bool operator==(const Key &rhs) 
//        {
//		RoadId == rhs.RoadId;
//        }
//        float getLinkId() const
//        {
//		return LinkId; 
//        }
//	operator long()
//	{
//		return RoadId;
//	} 
//private:
//	long RoadId;
//	float LinkId;
//};
//
//struct LinkComprator
//{
//public:
//	bool operator()(const Key &lhs, const Key &rhs)
//	{
//		return lhs.getLinkId() > rhs.getLinkId();
//	}
//};


class F_Network
{
public:
	long getID();
        void setID(long id);
        std::string  getName();
        void setName(std::string name);
        short getFRC();
        void setFRC(short frc);
        short getPJ();
        void setPJ(short pj);
        float getMeters();
        void setMeters(float meters);
        long getF_JNCTID();
        void setF_JNCTID(long f_jnctid);
        long getT_JNCTID();
        void setT_JNCTID(long t_jnctid);
        short getSliprd();
        void setSliprd(short sliprd);
        std::string getOneway();
        void setOneway(std::string oneway);
        short getF_ELEV();
        void setF_ELEV(short f_elev);
        short getT_ELEV();
        void setT_ELEV(short t_elev);
        short getKPH();
        void setKPH(short kph);
        float getMinutes();
        void setMinutes(float minutes);
        short getNOfShapePoints();
        void setNOfShapePoints(short noofshapepoints);
        void getCoordinateOfShapePoints(); 
        void setCoordinateOfShapePoints(std::string coordinates); 
        void printMember() ; 
        void cleanCoordinates();
        int getCoordinateSize();
        operator float(); 
private:
	long ID;
        std::string Name;
	short FRC;
	short PJ;
	float Meters;
	long F_JNCTID;
	long T_JNCTID;
	short Sliprd;
	std::string Oneway;
	short F_ELEV;
	short T_ELEV;
	short KPH;
	float Minutes;
	short NOfShapePoints;
	std::vector<std::string> CoordinateOfShapePoints;
};

class F_Network_Collection
{
public:
	void insertRoaddetails(F_Network &f_network) ;
	void ReadFile();
        void MemReadFile();
        void SearchRoad(long roadid);
        int getrecordcounts();
        void getLongestLink();
private:
	std::map<long, F_Network> F_NetworkColl;
};
