#include "F_Network.h"
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<cstring>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>

#define NUMINTS (65523)
#define FILESIZE (NUMINTS*sizeof(int))


long F_Network::getID()
{
	return ID;
}

void F_Network::setID(long id)
{
	ID = id;
}


std::string F_Network::getName()
{
	return Name;
}

void F_Network::setName(std::string name)
{
	Name = name;
}

short F_Network::getFRC()
{
	return FRC;
}

void F_Network::setFRC(short frc)
{
	FRC = frc; 
}

short F_Network::getPJ()
{
	return PJ;
}

void F_Network::setPJ(short pj)
{
	PJ = pj;
}

float F_Network::getMeters()
{
	return Meters;
}

void F_Network::setMeters(float meters)
{
	Meters = meters ;
}

long F_Network::getF_JNCTID()
{
	return F_JNCTID;
}

void F_Network::setF_JNCTID(long f_jnctid)
{
	F_JNCTID = f_jnctid;
}

long F_Network::getT_JNCTID()
{
	return T_JNCTID;
}

void F_Network::setT_JNCTID(long t_jnctid)
{
	T_JNCTID = t_jnctid ;
}

short F_Network::getSliprd()
{
	return Sliprd;
}

void F_Network::setSliprd(short sliprd)
{
	Sliprd = sliprd;
}

std::string F_Network::getOneway()
{
	return Oneway ;
}

void F_Network::setOneway(std::string oneway)
{
	Oneway = oneway ;
}

short F_Network::getF_ELEV()
{
	return F_ELEV;
}

void F_Network::setF_ELEV(short f_elev)
{
	F_ELEV = f_elev;
}

short F_Network::getT_ELEV()
{
	return T_ELEV;
}

void F_Network::setT_ELEV(short t_elev)
{
	T_ELEV = t_elev;
}

short F_Network::getKPH()
{
	return KPH;
}

void F_Network::setKPH(short kph)
{
	KPH = kph;
}

float F_Network::getMinutes()
{
	return Minutes;
}

void F_Network::setMinutes(float minutes)
{
	Minutes = minutes ;
}

short F_Network::getNOfShapePoints()
{
	return NOfShapePoints ;
}

F_Network::operator float()
{
	return Meters;
}

void F_Network::setNOfShapePoints(short noofshapepoints)
{
	NOfShapePoints = noofshapepoints;
}

void F_Network::setCoordinateOfShapePoints(std::string coordinates)
{
	CoordinateOfShapePoints.push_back(coordinates);
}

/***Key::Key(long roaid, float linkid)
***{
***RoadId = roaid;
***LinkId = linkid;
}****/

void F_Network::getCoordinateOfShapePoints()
{
        std::cout<<" Coordinate details are as below : "<<std::endl;
        std::string x;
        std::string y;
       
	for( std::vector<std::string>::iterator ite = CoordinateOfShapePoints.begin(); ite != CoordinateOfShapePoints.end(); ++ite)
        { 
		int i = 0;
		int pos = (*ite).find(" ");
                if(pos == -1)
                break;
		x = (*ite).substr(i, pos-i); 
		y = (*ite).substr(pos, std::string::npos); 
		std::cout<<" X is : "<< x ;
		std::cout<<" Y is : "<< y<<std::endl;
        }
  
}

void F_Network::cleanCoordinates()
{
	CoordinateOfShapePoints.clear();
}

int F_Network::getCoordinateSize()
{
	return CoordinateOfShapePoints.size();
}

void F_Network::printMember()
{
	std::cout<<" ID is: "<< getID() << std::endl;
	std::cout<<" Name is: "<< getName() << std::endl;
	std::cout<<" FRC is: "<< getFRC() << std::endl;
	std::cout<<" PJ is: "<< getPJ() << std::endl;
	std::cout<<" METERS is: "<< getMeters() << std::endl;
	std::cout<<" F_JNCTID is: "<< getF_JNCTID() << std::endl;
	std::cout<<" T_JNCTID is: "<< getT_JNCTID() << std::endl; 
	std::cout<<" Sliprd is: "<< getSliprd() << std::endl; 
	std::cout<<" Oneway is: "<< getOneway() << std::endl; 
	std::cout<<" F_ELEV is: "<< getF_ELEV() << std::endl; 
	std::cout<<" T_ELEV is: "<< getT_ELEV() << std::endl; 
	std::cout<<" KPH is: "<< getKPH() << std::endl; 
	std::cout<<" Minutes is: "<< getMinutes() << std::endl; 
	std::cout<<" NOfShapePoints is: "<< getNOfShapePoints() << std::endl; 
        getCoordinateOfShapePoints();
}

void F_Network_Collection::getLongestLink()
{
	int size = 0 ;
	int tempsize = 0;
        F_Network fnetwork;
	for(std::map<long,F_Network>::iterator ite = F_NetworkColl.begin(); ite != F_NetworkColl.end(); ite++)
	{
		tempsize = (ite->second).getCoordinateSize() ;
		if(size < tempsize )
		{
			size = tempsize;
                        fnetwork = ite->second ;
		}
	}
        std::cout<<" Details of longest link road is : "<<std::endl;
        std::cout<<" ============= "<<std::endl;
        std::cout<<" ============= "<<std::endl;
        fnetwork.printMember();
}

void F_Network_Collection::insertRoaddetails(F_Network &f_network)
{
                //Key key(f_network.getID(),f_network.getMeters());
                F_NetworkColl.insert(std::make_pair(f_network.getID(),f_network));
                //F_NetworkColl.insert(std::make_pair(key,f_network));
}

void F_Network_Collection::SearchRoad(long roadid)
{
	std::map<long,F_Network>::iterator ite = F_NetworkColl.find(roadid);
	//std::map<Key,F_Network>::iterator ite = F_NetworkColl.find(roadid);

	if(ite != F_NetworkColl.end())
	{
		std::cout<<" RoadId details are as below : "<<std::endl;
		std::cout<<" ===================== "<<std::endl;
		std::cout<<" ===================== "<<std::endl;
                ite->second.printMember();
	}
	else
	{
		std::cout<<"This is not a valid roadId : "<< std::endl; 
	}
}

int F_Network_Collection::getrecordcounts()
{
	return F_NetworkColl.size();
}


void F_Network_Collection::MemReadFile()
{
	int fd;
        int result;
        char *map;

	//fd = open("F_Network_out.txt",O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600)
	fd = open("F_Network_out.txt", O_RDONLY);
	if(fd == -1)
	{
		perror("Error opeining the file ");
		exit(EXIT_FAILURE);
	}
        
//        result = lseek(fd, FILESIZE-1, SEEK_SET);
//        if (result == -1)
//	{
//		//close(fd);
//		perror("Error calling lseek the file ");
//		exit(EXIT_FAILURE);
//	}
//  
//        result = write(fd,"",1);
//        if (result == -1)
//	{
//		//close(fd);
//		perror("Error writing to the file ");
//		exit(EXIT_FAILURE);
//	}
       
        struct stat st; 
        //if( stat("F_Network_out.txt",&st) != 0)
        //{
        //return 0; 
        //}
        stat("F_Network_out.txt",&st) ;
        size_t filesize = st.st_size;
 
        //map = (int *)mmap(0,FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        map = (char *)mmap(0,FILESIZE, PROT_READ , MAP_SHARED, fd, 0);
        //map = (char *)mmap(0,filesize, PROT_READ , MAP_SHARED, fd, 0);
        if (map == MAP_FAILED)
	{
		//close(fd);
		perror("Error mapping the file ");
		exit(EXIT_FAILURE);
	}

	std::string s;
        for(int i = 0 ; i <=NUMINTS; i++)
        { 
                if(map[i] != '\n' )
			s+= *(map+i);
                else
                {
			std::cout<<i<<"  "<<s;
			std::cout<<std::endl;
			s.clear();
                }
 

		//eor (int j= 0; map[j] != '\n'; j++)
		//{
		//	s+= *(map+j+i);
		//}
		//std::cout<<i<<"  "<<s;
		//std::cout<<std::endl;
         }
 
	if(munmap(map, FILESIZE) == -1)
	{
		perror("Error umapping the file ");
	} 

	//close(fd);

} 

void F_Network_Collection::ReadFile()
{
	std::string tmpString;
        int m_numLines = 0;
	std::ifstream txtFile("F_Network_out.txt");
        F_Network f_network;
	if(txtFile.is_open())
	{
	    while(txtFile.good())
	    {
		m_numLines++;
		getline(txtFile, tmpString);

                switch(m_numLines)
                {
			case 1:
				f_network.setID(std::atol(tmpString.c_str())); 
				break;
                        case 2:
				f_network.setName(tmpString);
				break;
                        case 3:
				f_network.setFRC(std::atoi(tmpString.c_str()));
				break;
                        case 4:
				f_network.setPJ(std::atoi(tmpString.c_str()));
				break;
                        case 5:
				f_network.setMeters(std::atof(tmpString.c_str()));
				break;
                        case 6:
				f_network.setF_JNCTID(std::atol(tmpString.c_str()));
				break;
                        case 7:
				f_network.setT_JNCTID(std::atol(tmpString.c_str()));
                                break;
                        case 8:
				f_network.setSliprd(std::atoi(tmpString.c_str()));
                                break;
                        case 9:
				f_network.setOneway(tmpString);
                                break;
                        case 10:
				f_network.setF_ELEV(std::atoi(tmpString.c_str()));
                                break;
                        case 11:
				f_network.setT_ELEV(std::atoi(tmpString.c_str()));
                                break;
                        case 12:
				f_network.setKPH(std::atoi(tmpString.c_str()));
                                break;
                        case 13:
				f_network.setMinutes(std::atof(tmpString.c_str()));
                                break;
                        case 14:
				f_network.setNOfShapePoints(std::atoi(tmpString.c_str()));
                                break;
                        default:
				f_network.setCoordinateOfShapePoints(tmpString);
				break; 
                }

                if(tmpString.empty())
                {
			m_numLines = 0 ;
			//f_network.printMember();
                        insertRoaddetails(f_network);
                        f_network.cleanCoordinates();
                }
	    }
	    txtFile.close();
	}
}

int main()
{
	clock_t tStart = clock();
	F_Network_Collection f_network_collection;
	f_network_collection.MemReadFile();
	double timetaken = (double)(clock() -tStart)/CLOCKS_PER_SEC ;
	std::cout<< " Time taken in processing file is : "<< timetaken<<std::endl;
	clock_t tStart1 = clock();
	f_network_collection.ReadFile();
	double timetaken1 = (double)(clock() -tStart1)/CLOCKS_PER_SEC ;
	std::cout<< " Time taken in processing file is : "<< timetaken1<<std::endl;
  
        int option; 
        do
        {
		std::cout<<" Options to query road details, Please select required one : "<<std::endl;
		std::cout<<"Enter 1 to query road details: "<<std::endl;
		std::cout<<"Enter 2 to know the number of records: "<<std::endl; 
		std::cout<<"Enter 3 to know the Longest Link: "<<std::endl; 
		std::cout<<"Enter 99 to exit: "<<std::endl; 
		std::cin>>option;
		switch(option)
		{
			case 1:
				long RoadId;
				std::cout<< " Enter the road id to be searched \n" ;
				std::cin>>RoadId;
				f_network_collection.SearchRoad(RoadId);
				break; 
			case 2:
				std::cout<<" Total records are : "<<f_network_collection.getrecordcounts()<<std::endl;
				std::cout<<" =============== "<<std::endl;
				std::cout<<" =============== "<<std::endl;
				break;
			case 3:
				//std::cout<<" Longest link is : "<<f_network_collection.getLongestLink()<<std::endl;
				f_network_collection.getLongestLink() ;
                                break;
			case 99: 
				break;

	 
		}
	} while(option != 99);
	return 0;
	}
