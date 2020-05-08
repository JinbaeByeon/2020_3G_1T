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
	//�ν��Ͻ�(Instancing)�� ���Ͽ� �޽��� ���� ��ü�鿡 ������ �� �ִ�. 
	//���� ������(Reference Count)�� �޽��� �����Ǵ� ���� ��ü�� ������ ��Ÿ����. 
	int m_nReferences = 1;

	//�޽��� �����ϴ� �ٰ���(��)���� ����Ʈ�̴�. 
	int m_nPolygons = 0;
	CPolygon** m_ppPolygons = NULL;
public:
	//�޽��� ���� ��ü�� ������ ������ �������� 1�� ������Ų��.  
	void AddRef() { m_nReferences++; }
	//�޽��� �����ϴ� ���� ��ü�� �Ҹ�� ������ �������� 1�� ���ҽ�Ų��. 
	//�������� 0�̵Ǹ� �޽��� �Ҹ��Ų��. 
	void Release() {
		m_nReferences--; if (m_nReferences <= 0) delete this;
	}
	void SetPolygon(int nIndex, CPolygon* pPolygon);
	//�޽��� �������Ѵ�. 
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
