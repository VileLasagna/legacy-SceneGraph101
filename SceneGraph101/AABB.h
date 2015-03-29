#ifndef AABB_H
#define AABB_H



class AABB
{
public:

	AABB(){Xm = 0; XM = 0; Ym = 0; YM = 0; Zm = 0; ZM = 0;}
	AABB(float Xmin, float Xmax, float Ymin, float Ymax, float Zmin, float Zmax) { Xm = Xmin; XM = Xmax; Ym = Ymin; YM = Ymax; Zm = Zmin; ZM = Zmax;}

	float Xm,XM,Ym,YM,Zm,ZM;

	AABB operator+ (const AABB& other) const 
	{
		if (this->isNull())
		{
			return other;
		}
		if (other.isNull())
		{
			return *this;
		}
		return AABB
		(Xm<other.Xm?Xm:other.Xm,
		XM>other.XM?XM:other.XM,
		Ym<other.Ym?Ym:other.Ym,
		YM>other.YM?YM:other.YM,
		Zm<other.Zm?Zm:other.Zm,
		ZM>other.ZM?ZM:other.ZM);
	}

	AABB operator += (const AABB& other)
	{
		*this = *this + other;
		return *this;
	}

	void Draw() const;

private:


	bool isNull() const
	{
		return (Xm == 0)&&(XM == 0)&&(Ym == 0)&&(YM == 0)&&(Zm == 0)&&(ZM == 0);
	}


};

#endif AABB_H