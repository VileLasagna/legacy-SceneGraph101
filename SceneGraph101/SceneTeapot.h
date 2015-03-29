#ifndef SCENE_TEAPOT_H
#define SCENE_TEAPOT_H

#include "SceneGraph.h"
#include <GL/glut.h>

class SceneTeapot: public SceneNode
{

public:
	SceneTeapot() {box = AABB(-3,3,-3,3,-3,3);}
	virtual void Draw() {glPushMatrix();mat.applyMatrix();glutSolidTeapot(3);glPopMatrix();}
	virtual ~SceneTeapot(){}
	void setTranslation(float x, float y, float z) {mat.setTranslation(x,y,z);}
	//virtual AABB getBox() const {return box;}
	virtual void DrawBox() const
	{
		SceneNode::DrawBox();
	}

};




#endif //SCENE_GRAPH_H