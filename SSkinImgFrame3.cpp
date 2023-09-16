#include "stdafx.h"
#include "SSkinImgFrame3.h"

SNSBEGIN

SSkinImgFrame3::SSkinImgFrame3(void)
{
}

SSkinImgFrame3::~SSkinImgFrame3(void)
{
}

ISkinObj *SSkinImgFrame3::Scale(int nScale)
{
	if(!m_bEnableScale)
		return __baseCls::Scale(nScale);

	SSkinImgFrame3 *skinObj = (SSkinImgFrame3*)SApplication::getSingleton().CreateSkinByName(GetObjectClass());
	if (!skinObj)
		return NULL;
	
	SSkinObjBase::_Scale(skinObj, nScale);
	//复制SSkinImgList的_Scale方法
	skinObj->m_nStates = m_nStates;
	skinObj->m_bTile = m_bTile;
	skinObj->m_bVertical = m_bVertical;
	skinObj->m_filterLevel = m_filterLevel;
	skinObj->m_bAutoFit = m_bAutoFit;
	skinObj->m_state2Index = m_state2Index;
	skinObj->m_bLazyLoad=FALSE;
	//图片不需要scale，直接使用源图
	skinObj->m_pImg = GetImage();

	//复制SSkinImgFrame的_Scale方法。
	int nSrcScale = GetScale();
	skinObj->m_rcMargin.left = MulDiv(m_rcMargin.left, nScale, nSrcScale);
	skinObj->m_rcMargin.top = MulDiv(m_rcMargin.top, nScale, nSrcScale);
	skinObj->m_rcMargin.right = MulDiv(m_rcMargin.right, nScale, nSrcScale);
	skinObj->m_rcMargin.bottom = MulDiv(m_rcMargin.bottom, nScale, nSrcScale);

	return skinObj;
}

void SSkinImgFrame3::_DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const 
{
	__baseCls::_DrawByIndex(pRT,rcDraw,iState,byAlpha);
	SSLOGI()<<"scale="<<GetScale()<<" margin="<<m_rcMargin.left<<","<<m_rcMargin.top<<","<<m_rcMargin.right<<","<<m_rcMargin.bottom;
}

SNSEND