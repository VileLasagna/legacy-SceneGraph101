#ifndef REF_COUNTED_H
#define REF_COUNTED_H


class RefCounted
{
public :
	RefCounted() : m_refCount (0) {}
	virtual ~RefCounted()  {}
	template <class T>
	friend class SmartPtr;

private:
	int m_refCount;
};

#endif //REF_COUNTED_H