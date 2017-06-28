#include <windows.h>
#include <math.h>



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "L2_Draw_Line";

void lineDDA(HDC hdc, double xh, double yh, double xk, double yk, COLORREF color)
{
	double x = xh + 0.5, y = yh + 0.5;
	int ixh = (int)floor(x);
	int iyh = (int)floor(y);

	int ixk = (int)floor(xk + 0.5);
	int iyk = (int)floor(yk + 0.5);

	int ilx = abs(ixk - ixh);
	int ily = abs(iyk - iyh);

	int l = max(ilx, ily);

	double dx = (double)(xk - xh) / l;
	double dy = (double)(yk - yh) / l;

	while (l--)
	{
		x += dx;
		y += dy;
		SetPixel(hdc, x, y, color);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;  
	MSG lpMsg;
	WNDCLASS wc;
	
	
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon		 = NULL;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = szClassName;


	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, "Cannot register class", "Error", MB_OK);
		return 0;
	}
	
	
	hWnd = CreateWindow( 
		    szClassName,				                  
            "L2 - draw line",	
            WS_OVERLAPPEDWINDOW,			                                           
            50,   50,						// Position for left top corner 
            600,  600,						//   width and height of the window 
            (HWND) NULL,					//  A pointer to the parent window NULL  
            (HMENU) NULL,					//      Use menu window class        
            (HINSTANCE)hInstance,			// A pointer to the current application
            NULL    );						//Is passed as lParam in the WM_CREATE event
	
	if (!hWnd) 
	{
		MessageBox(NULL, "Не удается создать главное окно!", "Ошибка", MB_OK);
		return 0;
	}


	ShowWindow(hWnd, nCmdShow); 
	UpdateWindow(hWnd);


	while (GetMessage(&lpMsg, NULL, 0, 0))  {
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}

	return (lpMsg.wParam);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	RECT Rect;
	HDC hdc, hCmpDC;
	HBITMAP hBmp;
	static int x1, y1, x2, y2, x3, y3;
	static int state = 0;
	static bool win_paint = false;

	switch (messg)
	{
		case WM_PAINT:
			GetClientRect(hWnd, &Rect);
			hdc = BeginPaint(hWnd, &ps);
			// Create a new context for double bufferization
			hCmpDC = CreateCompatibleDC(hdc);
			hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
				Rect.bottom - Rect.top);
			SelectObject(hCmpDC, hBmp);
			// Rendering background color
			LOGBRUSH br;
			br.lbStyle = BS_SOLID;
			br.lbColor = 0x000000;
			HBRUSH brush;
			brush = CreateBrushIndirect(&br);
			FillRect(hCmpDC, &Rect, brush);
			DeleteObject(brush);
			//SetStretchBltMode(hdc, COLORONCOLOR);

			lineDDA(hCmpDC, 10, 10, 200, 200, 0x0FFFFF);

			SetStretchBltMode(hdc, COLORONCOLOR);
			BitBlt(hdc, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top,
				hCmpDC, 0, 0, SRCCOPY);
			DeleteDC(hCmpDC);
			DeleteObject(hBmp);
			hCmpDC = NULL;
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return (DefWindowProc(hWnd, messg, wParam, lParam));
	}

	return 0;
}
