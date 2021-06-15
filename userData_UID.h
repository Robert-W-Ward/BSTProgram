#pragma once
#include <string>
struct userData_UID
{
	std::string UID;
	int ticknum;
	userData_UID():ticknum(),UID(){}
	userData_UID(std::string UID, int ticknum) :UID(UID), ticknum(ticknum){}
	bool operator==(userData_UID ud)
	{
		if(UID == ud.UID)
		{
			return true;
		}
		return false;
	}
	bool operator>(userData_UID ud)
	{
		if(UID>ud.UID)
		{
			return true;
		}
		return false;
	}
	bool operator<(userData_UID ud)
	{
		if(UID < ud.UID)
		{
			return true;
		}
		return false;
	}

};

