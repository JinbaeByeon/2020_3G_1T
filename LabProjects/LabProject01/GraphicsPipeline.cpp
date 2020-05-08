#include "stdafx.h"
#include "GraphicsPipeline.h"

CGameObject* CGraphicsPipeline::m_pGameObject = NULL;
CCamera* CGraphicsPipeline::m_pCamera = NULL;

XMVECTOR CGraphicsPipeline::Transform(XMFLOAT3& f3Model)
{
	XMVECTOR v3Model = XMLoadFloat3(&f3Model);

	XMMATRIX m_WorldMatrix = m_pGameObject->WorldTransform();
	XMMATRIX m_ViewMatrix = m_pCamera->GenerateViewTransform();
	XMMATRIX m_ProjectMatrix = m_pCamera->ProjectionTransform();
	XMMATRIX m_ScreenMatrix = m_pCamera->ScreenTransform();
	XMMATRIX M = XMMatrixMultiply(XMMatrixMultiply(XMMatrixMultiply(m_WorldMatrix, m_ViewMatrix), m_ProjectMatrix), m_ScreenMatrix);

	return XMVector3Transform(v3Model, M);

}

XMVECTOR CGraphicsPipeline::Project(XMFLOAT3& f3Model)
{
	XMVECTOR v3Model = XMLoadFloat3(&f3Model);

	XMMATRIX m_WorldMatrix = m_pGameObject->WorldTransform();
	XMMATRIX m_ViewMatrix = m_pCamera->GenerateViewTransform();
	XMMATRIX m_ProjectMatrix = m_pCamera->ProjectionTransform();
	XMMATRIX M = XMMatrixMultiply(XMMatrixMultiply(m_WorldMatrix, m_ViewMatrix), m_ProjectMatrix);

	XMVECTOR v4Projection = XMVector3Transform(v3Model, M);
	if (!IsZero(XMVectorGetW(v4Projection)))
		v4Projection /= fabsf(XMVectorGetW(v4Projection));
	
	return v4Projection;
}

XMVECTOR XM_CALLCONV CGraphicsPipeline::ScreenTransform(FXMVECTOR& v3Projection)
{
	XMMATRIX m_ScreenMatrix = m_pCamera->ScreenTransform();

	return XMVector3Transform(v3Projection, m_ScreenMatrix);
}

