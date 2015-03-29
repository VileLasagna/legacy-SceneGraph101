#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include "RefCounted.h"
#include "SmartPtr.h"
#include "Matrix44.h"
#include "AABB.h"
#include <windows.h>
#include <GL/gl.h>
#include <vector>

class SceneNode;
//typedef SmartPtr<SceneNode> SceneNodePTR;
typedef SceneNode* SceneNodePTR;


class SceneNode: public RefCounted
{
public:

	virtual void Draw() = 0;

	virtual ~SceneNode(){};

	virtual void addChild(SceneNode* child){}
	virtual AABB getBox() const
	{
		Vec4f boxMin(box.Xm,box.Ym,box.Zm,1);
		Vec4f boxMax(box.XM,box.YM,box.ZM,1);
		boxMin =  Matrix44::Multiply(CombinedTransform,boxMin);
		boxMax =  Matrix44::Multiply(CombinedTransform,boxMax);
		return AABB(boxMin.X(),boxMax.X(),boxMin.Y(),boxMax.Y(),boxMin.Z(),boxMax.Z());
	}
	virtual void DrawBox() const
	{
		getBox().Draw();
	}

	Matrix44* getMatrix() {return &mat;}

	virtual void ResetTransform() {CombinedTransform.setIdentity();}
	virtual void CascadeTransform(const Matrix44& M = Matrix44()) {Matrix44 mult = M; mult.Multiply(CombinedTransform);mult.Multiply(mat); CombinedTransform = mult;}
	

protected:

	

	Matrix44 mat;
	Matrix44 CombinedTransform;
	AABB box;

};

class SceneComposite : public SceneNode
{

public:

	void Draw(){glPushMatrix();mat.applyMatrix();for( unsigned int i = 0; i < children.size(); i++){children[i]->Draw();}glPopMatrix(); }

	virtual ~SceneComposite(){}

	void addChild(SceneNode* child) {children.push_back(child);}
	virtual void ResetTransform()
	{
		SceneNode::ResetTransform();
		for(unsigned int i = 0; i < children.size(); i++)
		{
			children[i]->ResetTransform();
		}
	}
	virtual void CascadeTransform(const Matrix44& M = Matrix44())
	{
		SceneNode::CascadeTransform(M);
		for(unsigned int i = 0; i < children.size(); i++)
		{
			children[i]->CascadeTransform(CombinedTransform);
		}
	}

	virtual AABB getBox() const
	{
		AABB ret;
		for(unsigned int i = 0; i < children.size(); i++)
		{
			ret += children[i]->getBox();
		}
		return ret;
	}
	virtual void DrawBox() const
	{
		getBox().Draw();
		for(unsigned int i = 0; i < children.size(); i++)
		{
			children[i]->DrawBox();
		}

	}

private:

	std::vector<SceneNodePTR> children;
};






#endif //SCENE_GRAPH_H