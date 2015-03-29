#include "AABB.h"
#include "Vec3.h"
#include <windows.h>
#include <GL/gl.h>


void DrawLine(const Vec3f& v1, const Vec3f& v2)
{
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_LIGHTING);
  glBegin(GL_LINES);
  glVertex3f(v1.X(), v1.Y(), v1.Z());
  glVertex3f(v2.X(), v2.Y(), v2.Z());
  glEnd();
  glEnable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
}

void AABB::Draw() const
{
  DrawLine(Vec3f(Xm, Ym, Zm), 
				   Vec3f(XM, Ym, Zm));

  DrawLine(Vec3f(XM, Ym, Zm), 
				   Vec3f(XM, Ym, ZM));

  DrawLine(Vec3f(XM, Ym, ZM), 
				   Vec3f(Xm, Ym, ZM));

  DrawLine(Vec3f(Xm, Ym, ZM), 
				   Vec3f(Xm, Ym, Zm));

  DrawLine(Vec3f(Xm, YM, Zm), 
				   Vec3f(XM, YM, Zm));

  DrawLine(Vec3f(XM, YM, Zm), 
				   Vec3f(XM, YM, ZM));

  DrawLine(Vec3f(XM, YM, ZM), 
				   Vec3f(Xm, YM, ZM));

  DrawLine(Vec3f(Xm, YM, ZM), 
				   Vec3f(Xm, YM, Zm));

  DrawLine(Vec3f(Xm, Ym, Zm), 
				   Vec3f(Xm, YM, Zm));

  DrawLine(Vec3f(XM, Ym, Zm), 
				   Vec3f(XM, YM, Zm));

  DrawLine(Vec3f(XM, Ym, ZM), 
				   Vec3f(XM, YM, ZM));

  DrawLine(Vec3f(Xm, Ym, ZM), 
				   Vec3f(Xm, YM, ZM));
}



