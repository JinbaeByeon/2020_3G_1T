#include "Mesh.h"
#include "GraphicsPipeline.h"

CPolygon::CPolygon(int nVertices)
{
	m_nVertices = nVertices;
	m_pVertices = new CVertex[nVertices];
}

CPolygon::~CPolygon()
{
	if (m_pVertices) delete[] m_pVertices;
}
void CPolygon::SetVertex(int nIndex, CVertex vertex)
{
	if ((0 <= nIndex) && (nIndex < m_nVertices) && m_pVertices)
	{
		m_pVertices[nIndex] = vertex;
	}
}

CMesh::CMesh(int nPolygons)
{
	m_nPolygons = nPolygons;
	m_ppPolygons = new CPolygon * [nPolygons];
}
CMesh::~CMesh()
{
	if (m_ppPolygons)
	{
		delete[] m_ppPolygons;
	}
}

void CMesh::SetPolygon(int nIndex, CPolygon* pPolygon)
{
	//�޽��� �ٰ����� �����Ѵ�.  
	if ((0 <= nIndex) && (nIndex < m_nPolygons)) m_ppPolygons[nIndex] = pPolygon;
}

void Draw2DLine(HDC hDCFrameBuffer, CPoint3D& f3PreviousProject,
	CPoint3D& f3CurrentProject)
{
	//���� ��ǥ���� 2���� ȭ�� ��ǥ��� ��ȯ�ϰ� ��ȯ�� �� ��(�ȼ�)�� �������� �׸���.  
	CPoint3D f3Previous =
		CGraphicsPipeline::ScreenTransform(f3PreviousProject);
	CPoint3D f3Current =
		CGraphicsPipeline::ScreenTransform(f3CurrentProject);
	::MoveToEx(hDCFrameBuffer, (long)f3Previous.x, (long)f3Previous.y, NULL);
	::LineTo(hDCFrameBuffer, (long)f3Current.x, (long)f3Current.y);
}

void CMesh::Render(HDC hDCFrameBuffer)
{
	CPoint3D f3InitialProject, f3PreviousProject, f3Intersect;
	bool bPreviousInside = false, bInitialInside = false,
		bCurrentInside = false, bIntersectInside = false;
	//�޽��� �����ϴ� ��� �ٰ������� �������Ѵ�. 
	for (int j = 0; j < m_nPolygons; j++)
	{
		int nVertices = m_ppPolygons[j]->m_nVertices;
		CVertex* pVertices = m_ppPolygons[j]->m_pVertices;
		//�ٰ����� ù ��° ������ ���� ���� ��ȯ�Ѵ�.  
		f3PreviousProject = f3InitialProject =
			CGraphicsPipeline::Project(pVertices[0].m_f3Position);
		//��ȯ�� ���� ���� �簢���� ���ԵǴ� ���� ����Ѵ�.
		bPreviousInside = bInitialInside = (-1.0f <=
			f3InitialProject.x) && (f3InitialProject.x <= 1.0f) && (-1.0f <=
				f3InitialProject.y) && (f3InitialProject.y <= 1.0f);
		//�ٰ����� �����ϴ� ��� �������� ���� ���� ��ȯ�ϰ� �������� �������Ѵ�. 
		for (int i = 1; i < nVertices; i++)
		{
			CPoint3D f3CurrentProject = CGraphicsPipeline::Project(pVertices[i].m_f3Position);
			//��ȯ�� ���� ���� �簢���� ���ԵǴ� ���� ����Ѵ�.
			bCurrentInside = (-1.0f <= f3CurrentProject.x) &&
				(f3CurrentProject.x <= 1.0f) && (-1.0f <= f3CurrentProject.y) &&
				(f3CurrentProject.y <= 1.0f);
			//��ȯ�� ���� ���� �簢���� ���ԵǸ� ���� ���� ���� ���� �������� �׸���.
			if (((f3PreviousProject.z >= 0.0f) || (f3CurrentProject.z >=
				0.0f)) && ((bCurrentInside || bPreviousInside)))
				::Draw2DLine(hDCFrameBuffer, f3PreviousProject, f3CurrentProject);
			f3PreviousProject = f3CurrentProject;
		} bPreviousInside = bCurrentInside;
		//�ٰ����� ������ ������ �ٰ����� �������� �������� �׸���.
		if (((f3PreviousProject.z >= 0.0f) || (f3InitialProject.z >=
			0.0f)) && ((bInitialInside || bPreviousInside)))
			::Draw2DLine(hDCFrameBuffer, f3PreviousProject, f3InitialProject);
	}
}

CCubeMesh::CCubeMesh(float fWidth, float fHeight, float fDepth)
{
	m_nPolygons = 6;
	m_ppPolygons = new CPolygon * [6];

	// ���� 8��
	CVertex v1(-fWidth / 2, fHeight / 2, -fDepth / 2);
	CVertex v2(-fWidth / 2, fHeight / 2, fDepth / 2);
	CVertex v3(fWidth / 2, fHeight / 2, fDepth / 2);
	CVertex v4(fWidth / 2, fHeight / 2, -fDepth / 2);
	CVertex v5(-fWidth / 2, -fHeight / 2, -fDepth / 2);
	CVertex v6(-fWidth / 2, -fHeight / 2, fDepth / 2);
	CVertex v7(fWidth / 2, -fHeight / 2, fDepth / 2);
	CVertex v8(fWidth / 2, -fHeight / 2, -fDepth / 2);

	// �� 6��
	CPolygon* p1 = new CPolygon(4);
	p1->SetVertex(0, v1);
	p1->SetVertex(1, v2);
	p1->SetVertex(2, v3);
	p1->SetVertex(3, v4);
	CPolygon* p2 = new CPolygon(4);
	p2->SetVertex(0, v1);
	p2->SetVertex(1, v4);
	p2->SetVertex(2, v8);
	p2->SetVertex(3, v5);
	CPolygon* p3 = new CPolygon(4);
	p3->SetVertex(0, v4);
	p3->SetVertex(1, v3);
	p3->SetVertex(2, v7);
	p3->SetVertex(3, v8);
	CPolygon* p4 = new CPolygon(4);
	p4->SetVertex(0, v3);
	p4->SetVertex(1, v2);
	p4->SetVertex(2, v6);
	p4->SetVertex(3, v7);
	CPolygon* p5 = new CPolygon(4);
	p5->SetVertex(0, v1);
	p5->SetVertex(1, v5);
	p5->SetVertex(2, v6);
	p5->SetVertex(3, v2);
	CPolygon* p6 = new CPolygon(4);
	p6->SetVertex(0, v8);
	p6->SetVertex(1, v7);
	p6->SetVertex(2, v6);
	p6->SetVertex(3, v5);

	SetPolygon(0, p1);
	SetPolygon(1, p2);
	SetPolygon(2, p3);
	SetPolygon(3, p4);
	SetPolygon(4, p5);
	SetPolygon(5, p6);
}
