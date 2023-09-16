#pragma once

SNSBEGIN

class SSkinImgFrame3 : public SSkinImgFrame
{
	DEF_SOBJECT(SSkinImgFrame,L"imgFrame3")
public:
	SSkinImgFrame3(void);
	~SSkinImgFrame3(void);

public:
	STDMETHOD_(ISkinObj *, Scale)(THIS_ int nScale) OVERRIDE;

protected:
	void _DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const override;
};

SNSEND