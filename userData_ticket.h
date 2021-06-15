#pragma once
#include <string>
struct userData_ticket
{
	std::string UID;
	int ticknum;
	userData_ticket():ticknum(),UID(""){}
	userData_ticket(std::string UID, int ticknum) :UID(UID), ticknum(ticknum){}
	bool operator==(userData_ticket ud)
	{
		if(ticknum == ud.ticknum )
		{
			return true;
		}

		return false;
	}
	bool operator<(userData_ticket ud)
	{
		if(ticknum < ud.ticknum)
		{
			return true;
		}
		return false;
	}
	bool operator>(userData_ticket ud)
	{
		if(ticknum > ud.ticknum)
		{
			return true;
		}
		return false;
	}
	

	
};

