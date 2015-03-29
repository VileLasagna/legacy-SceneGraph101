#ifndef MEMORY_H
#define MEMORY_H

#ifdef MEM_DEBUG

	void* operator new (size_t size, const char* filename, int line);
	void operator delete (void* p);
	#define new new (__FILE__, __LINE__)

#endif

#endif