#ifndef SMART_H
#define SMART_H
template <class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr  = 0) : m_ptr(ptr) 
	{
		if(m_ptr)
		{
			++(m_ptr->m_refCount);
		}
	}
	T* operator->(){ return m_ptr;}
	operator T* () const {return m_ptr;}
	~SmartPtr()
	{
		if(m_ptr)
		{
			--(m_ptr->m_refCount);
			if (m_ptr->m_refCount <= 0)
			{
				delete m_ptr;
			}
		}
	}

	SmartPtr(const SmartPtr& s) : m_ptr(s.m_ptr)
	{
		if (m_ptr)
		{
			++(m_ptr->m_refCount);
		}
	}

	SmartPtr& operator=(const SmartPtr& s)
	{
		if(this == &s)
		{

			if(s.m_ptr)
			{
				++(s.m_ptr->m_refCount);
			}
			if (m_ptr)
			{
				--(m_ptr->m_refCount);
				if (m_ptr->m_refCount == 0)
				{
					delete m_ptr;
				}
			}
			m_ptr = s.m_ptr;
			return *this;

		}
		return *this;
	}

private:

	T* m_ptr;
};



#endif