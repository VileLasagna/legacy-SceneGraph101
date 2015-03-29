#ifndef SMART_POINTER_DEFINED
#define SMART_POINTER_DEFINED

class RefCounted
{
public:

	RefCounted() : refCount(0) {}
	virtual ~RefCounted();

private:

	int refCount;


};







#endif //SMART_POINTER_DEFINED