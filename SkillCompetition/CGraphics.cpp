#include "framework.h"

CGraphics::CGraphics()
{
	m_factory = NULL;
	m_renderTarget = NULL;
	m_Redbrush = NULL;
	
}

CGraphics::~CGraphics()
{
}

INT CGraphics::Init(HWND hWnd, RECT rcWin)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
	if (res != S_OK)
		return -1;

	res = m_factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd,
			D2D1::SizeU(rcWin.right - rcWin.left, rcWin.bottom - rcWin.top)),
			&m_renderTarget);
	if (res != S_OK) return -1;

	res = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &m_Redbrush);
	res = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_Blackbrush);
	res = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_Whitebrush);


	res = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_renderTarget));

	m_writeFactory->CreateTextFormat(
		L"Gabiola",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		30.0f,
		L"",
		&m_format
	);

	return 0;
}

void CGraphics::CleanUp()
{
}

void CGraphics::CleanScreen(float r, float g, float b)
{
}

void CGraphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
}

void CGraphics::DrawTextOut(LPCWSTR text, D2D1_POINT_2F Pos)
{
}
