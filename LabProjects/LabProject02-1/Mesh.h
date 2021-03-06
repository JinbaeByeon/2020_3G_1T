#pragma once
#include "stdafx.h"

class CPoint3D
{
public:
	CPoint3D() {}
	CPoint3D(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
};

class CVertex
{
public:
	CVertex() {}
	CVertex(float x, float y, float z) {
		m_f3Position = CPoint3D(x, y, z);
	}
	virtual ~CVertex() { }

	CPoint3D m_f3Position;
};

class CPolygon
{
public:
	CPolygon() { }
	CPolygon(int nVertices);
	virtual ~CPolygon();


	int m_nVertices = 0;
	CVertex* m_pVertices = NULL;

	void SetVertex(int nIndex, CVertex vertex);
};


class CMesh
{
public:
	CMesh() { }
	CMesh(int nPolygons);
	virtual ~CMesh();
protected:
	//인스턴싱(Instancing)을 위하여 메쉬는 게임 객체들에 공유될 수 있다. 
	//다음 참조값(Reference Count)은 메쉬가 공유되는 게임 객체의 개수를 나타낸다. 
	int m_nReferences = 1;

	//메쉬를 구성하는 다각형(면)들의 리스트이다. 
	int m_nPolygons = 0;
	CPolygon** m_ppPolygons = NULL;
public:
	//메쉬가 게임 객체에 공유될 때마다 참조값을 1씩 증가시킨다.  
	void AddRef() { m_nReferences++; }
	//메쉬를 공유하는 게임 객체가 소멸될 때마다 참조값을 1씩 감소시킨다. 
	//참조값이 0이되면 메쉬를 소멸시킨다. 
	void Release() {
		m_nReferences--; if (m_nReferences <= 0) delete this;
	}
	void SetPolygon(int nIndex, CPolygon* pPolygon);
	//메쉬를 렌더링한다. 
	virtual void Render(HDC hDCFrameBuffer);
};

class CCubeMesh : public CMesh
{
public:
	CCubeMesh() {}
	CCubeMesh(float fWidth = 4.0f, float fHeight = 4.0f, float fDepth
		= 4.0f);
	virtual ~CCubeMesh() { CMesh::~CMesh(); }
private:
public:

};
