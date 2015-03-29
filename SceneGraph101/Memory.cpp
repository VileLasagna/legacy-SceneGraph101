#include <stdlib.h>
#include <map>
#include "Singleton.h"
#include <iostream>
#include <assert.h>
#include <string>
#include "Memory.h"


#undef new 


#ifdef MEM_DEBUG


int depth = 0;
static size_t s_totalAllocated = 0;
static const size_t MAX_HEAP = 20; 

struct Allocation 
{	
	std::string m_filename;
	int m_lineNum;
	void* m_ptr;
	size_t m_size;


	Allocation() : 	m_ptr(0), m_size(0),  m_lineNum(0)
	{
	}

	Allocation(void* p, size_t s , const std::string& filename, int lineNum) : m_ptr(0), m_size(0), m_filename(filename), m_lineNum(lineNum)
	{

	}
};

	struct AllocManager
	{
		typedef std::map<void*, Allocation> Allocmap;

		Allocmap m_map;

		void CreateAlloc(void* p, size_t size, const char* filename, int lineNum)
		{
			if (s_totalAllocated > MAX_HEAP)
			{
				assert(0);
			}
			s_totalAllocated += size;
			m_map[p] = Allocation (p,size, filename, lineNum);
		}



		void RemoveAllocation(void* p)
		{
			size_t size = m_map[p].m_size;
			s_totalAllocated -= size;
			m_map.erase(p);
		}	

		~AllocManager()
		{
			++depth;
			PrintMap();
		}


		void PrintMap()
		{
			for(Allocmap::iterator it = m_map.begin(); it != m_map.end(); ++it)
			{
				std::cout << "Leak! " << it->first << " Size" << it->second.m_size <<  " Filename " << it->second.m_filename;
			}
		}
	};
	typedef Singleton<AllocManager> TheAllocManager;






	void* operator new (size_t size, const char* filename, int line)
	{


		void* ptr = malloc(size);
		depth++;
		if (depth == 1)
		{
			TheAllocManager::Instance()->CreateAlloc(ptr, size, filename, line);
		}
		--depth;
		return ptr;
	}




	void operator delete (void* p)
	{
		if (p)
		{
			++depth;
			if(depth == 1)
			{
				TheAllocManager::Instance()->RemoveAllocation(p);

			}
			--depth;
			free(p);
		}
	}

#endif