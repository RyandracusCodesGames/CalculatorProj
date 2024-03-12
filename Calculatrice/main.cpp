#include <Windows.h>
#include <iostream>
#include <vector>
#include "calculatrice.h"
#include "image.h"
#include "input.h"

/*Game-loop termiating variable*/
static bool quit;
/*WinAPI Structures Setup*/
static BITMAPINFO frame_bitmap_info;
static HBITMAP frame_bitmap = 0;
static HDC frame_device_context = 0;
/*WinAPI callback function designed to process window display info such as graphics and keyboard input*/
LRESULT CALLBACK WindowProcessMessage(HWND, UINT, WPARAM, LPARAM);

/*Varibles to hold current system time in miliseconds*/
LARGE_INTEGER gTimerFreq;
LARGE_INTEGER gTimerStart;

Input* input = new Input;

Image* zero = new Image, * period = new Image, * one = new Image, * two = new Image;
Image* three = new Image, * four = new Image, * five = new Image, * six = new Image;
Image* seven = new Image, * eight = new Image, * nine = new Image;
Image* equal = new Image, * add = new Image, * sub = new Image, * mul = new Image;
Image* divv = new Image, * per = new Image, * clear = new Image, * ce = new Image;
Image* bar = new Image, *decimal = new Image, *plus = new Image, *mult = new Image;
Image* num_zero = new Image, *num_one = new Image, *num_two = new Image, *num_three = new Image, *num_four = new Image;
Image* num_five = new Image, *num_six = new Image, *num_seven = new Image, *num_eight = new Image, *num_nine = new Image;
Image* minus = new Image, *divide = new Image, *percent = new Image, *result = new Image, *per_sign = new Image;
Image* calc_1 = new Image, * calc_2 = new Image, * trace_1 = new Image, * trace_2 = new Image;
Image* a = new Image, * b = new Image, * c = new Image, * d = new Image, * e = new Image, * f = new Image, * g = new Image;
Image* h = new Image, * ii = new Image, * j = new Image, * k = new Image, * l = new Image, * m = new Image, * n = new Image;
Image* o = new Image, * p = new Image, * q = new Image, * r = new Image, * s = new Image, * t = new Image, * u = new Image;
Image* v = new Image, * w = new Image, * xx = new Image, * y = new Image, * z = new Image;

int trace_index = 0;

void timerInit()
{
	QueryPerformanceFrequency(&gTimerFreq);
	QueryPerformanceCounter(&gTimerStart);
}

long osGetSystemTimeMS()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return (long)((count.QuadPart - gTimerStart.QuadPart) * 1000L / gTimerFreq.QuadPart);
}

void Init(){
	LoadImg(zero, "images/zero.img");
	LoadImg(period, "images/period.img");
	LoadImg(one, "images/one.img");
	LoadImg(two, "images/two.img");
	LoadImg(three, "images/three.img");
	LoadImg(four, "images/four.img");
	LoadImg(five, "images/five.img");
	LoadImg(six, "images/six.img");
	LoadImg(seven, "images/seven.img");
	LoadImg(eight, "images/eight.img");
	LoadImg(nine, "images/nine.img");
	LoadImg(equal, "images/equal.img");
	LoadImg(per, "images/per.img");
	LoadImg(mul, "images/mul.img");
	LoadImg(divv, "images/div.img");
	LoadImg(add, "images/add.img");
	LoadImg(sub, "images/sub.img");
	LoadImg(clear, "images/clear.img");
	LoadImg(ce, "images/ce.img");
	LoadImg(bar, "images/bar.img");
	LoadImg(num_zero, "images/num_zero.img");
	LoadImg(num_one, "images/num_one.img");
	LoadImg(num_two, "images/num_two.img");
	LoadImg(num_three, "images/num_three.img");
	LoadImg(num_four, "images/num_four.img");
	LoadImg(num_five, "images/num_five.img");
	LoadImg(num_six, "images/num_six.img");
	LoadImg(num_seven, "images/num_seven.img");
	LoadImg(num_eight, "images/num_eight.img");
	LoadImg(num_nine, "images/num_nine.img");
	LoadImg(decimal, "images/decimal.img");
	LoadImg(plus, "images/plus.img");
	LoadImg(mult, "images/mult.img");
	LoadImg(minus, "images/minus.img");
	LoadImg(divide, "images/divide.img");
	LoadImg(result, "images/result.img");
	LoadImg(per_sign, "images/percent.img");
	LoadImg(calc_1, "images/calc_1.img");
	LoadImg(calc_2, "images/calc_2.img");
	LoadImg(trace_1, "images/trace_1.img");
	LoadImg(trace_2, "images/trace_2.img");

	LoadImg(a, "images/A.img");
	LoadImg(b, "images/B.img");
	LoadImg(c, "images/C.img");
	LoadImg(d, "images/D.img");
	LoadImg(e, "images/E.img");
	LoadImg(f, "images/F.img");
	LoadImg(g, "images/G.img");
	LoadImg(h, "images/H.img");
	LoadImg(ii, "images/I.img");
	LoadImg(j, "images/J.img");
	LoadImg(k, "images/K.img");
	LoadImg(l, "images/L.img");
	LoadImg(m, "images/M.img");
	LoadImg(n, "images/N.img");
	LoadImg(o, "images/O.img");
	LoadImg(p, "images/P.img");
	LoadImg(q, "images/Q.img");
	LoadImg(r, "images/R.img");
	LoadImg(s, "images/S.img");
	LoadImg(t, "images/T.img");
	LoadImg(u, "images/U.img");
	LoadImg(v, "images/V.img");
	LoadImg(w, "images/W.img");
	LoadImg(xx, "images/X.img");
	LoadImg(y, "images/Y.img");
	LoadImg(z, "images/Z.img");
}

void Cleanup(){
	delete zero; delete one; delete two; delete three; delete four; delete five; delete six; delete seven;
	delete eight; delete nine; delete period;
	delete equal; delete add; delete sub; delete divv; delete mul; delete per; delete ce; delete clear;
	delete bar; delete num_one; delete num_two; delete num_three; delete num_four; delete num_five;
	delete num_six; delete num_seven; delete num_eight; delete num_nine; delete result; delete per_sign;
	delete input; delete decimal; delete plus; delete minus; delete divide; delete percent; delete mult;
	delete calc_1; delete calc_2; delete trace_1; delete trace_2;
	delete a; delete b; delete c; delete d; delete e; delete f; delete g; delete h; delete ii;
	delete j; delete k; delete l; delete m; delete n; delete o; delete p; delete q; delete r;
	delete s; delete t; delete u; delete v; delete w; delete xx; delete y; delete z;
}

void BlitToScreen(HWND window_handle) {
	static HDC device_context;
	device_context = GetDC(window_handle);
	RECT window_rect;
	GetClientRect(window_handle, &window_rect);
	BitBlt(device_context, 0, 0, WIDTH, HEIGHT, frame_device_context, 0, 0, SRCCOPY);
	ReleaseDC(window_handle, device_context);
}

void DrawString(uint32_t* vram, int tx, int ty, uint32_t chromakey, std::string str){
	int i, x = tx;
	for (i = str.length(); i >= 0; i--){
		char cc = str[i];

		x -= num_one->width;

		if (cc == '+' || cc == '-' || cc == '/') {
			x -= 8;
		}

		if (cc == '*') {
			x -= 8;
		}

		switch (cc){
			case '0':{
				DisplayImage(vram, x, ty, chromakey, num_zero);
			}break;
			case '1': {
				DisplayImage(vram, x, ty, chromakey, num_one);
			}break;
			case '2': {
				DisplayImage(vram, x, ty, chromakey, num_two);
			}break;
			case '3': {
				DisplayImage(vram, x, ty, chromakey, num_three);
			}break;
			case '4': {
				DisplayImage(vram, x, ty, chromakey, num_four);
			}break;
			case '5': {
				DisplayImage(vram, x, ty, chromakey, num_five);
			}break;
			case '6': {
				DisplayImage(vram, x, ty, chromakey, num_six);
			}break;
			case '7': {
				DisplayImage(vram, x, ty, chromakey, num_seven);
			}break;
			case '8': {
				DisplayImage(vram, x, ty, chromakey, num_eight);
			}break;
			case '9': {
				DisplayImage(vram, x, ty, chromakey, num_nine);
			}break;
			case 'A': {
				DisplayImage(vram, x, ty, chromakey, a);
			}break;
			case 'B': {
				DisplayImage(vram, x, ty, chromakey, b);
			}break;
			case 'C': {
				DisplayImage(vram, x, ty, chromakey, c);
			}break;
			case 'D': {
				DisplayImage(vram, x, ty, chromakey, d);
			}break;
			case 'E': {
				DisplayImage(vram, x, ty, chromakey, e);
			}break;
			case 'F': {
				DisplayImage(vram, x, ty, chromakey, f);
			}break;
			case 'G': {
				DisplayImage(vram, x, ty, chromakey, g);
			}break;
			case 'H': {
				DisplayImage(vram, x, ty, chromakey, h);
			}break;
			case 'I': {
				DisplayImage(vram, x, ty, chromakey, ii);
			}break;
			case 'J': {
				DisplayImage(vram, x, ty, chromakey, j);
			}break;
			case 'K': {
				DisplayImage(vram, x, ty, chromakey, k);
			}break;
			case 'L': {
				DisplayImage(vram, x, ty, chromakey, l);
			}break;
			case 'M': {
				DisplayImage(vram, x, ty, chromakey, m);
			}break;
			case 'N': {
				DisplayImage(vram, x, ty, chromakey, n);
			}break;
			case 'O': {
				DisplayImage(vram, x, ty, chromakey, o);
			}break;
			case 'P': {
				DisplayImage(vram, x, ty, chromakey, p);
			}break;
			case 'Q': {
				DisplayImage(vram, x, ty, chromakey, q);
			}break;
			case 'R': {
				DisplayImage(vram, x, ty, chromakey, r);
			}break;
			case 'S': {
				DisplayImage(vram, x, ty, chromakey, s);
			}break;
			case 'T': {
				DisplayImage(vram, x, ty, chromakey, t);
			}break;
			case 'U': {
				DisplayImage(vram, x, ty, chromakey, u);
			}break;
			case 'V': {
				DisplayImage(vram, x, ty, chromakey, v);
			}break;
			case 'W': {
				DisplayImage(vram, x, ty, chromakey, w);
			}break;
			case 'X': {
				DisplayImage(vram, x, ty, chromakey, xx);
			}break;
			case 'Y': {
				DisplayImage(vram, x, ty, chromakey, y);
			}break;
			case 'Z': {
				DisplayImage(vram, x, ty, chromakey, z);
			}break;
			case '.': {
				DisplayImage(vram, x, ty, chromakey, decimal);
			}break;
			case '+': {
				DisplayImage(vram, x, ty, chromakey, plus);

				x -= 5;
			}break;
			case '-': {
				DisplayImage(vram, x, ty, chromakey, minus);

				x -= 5;
			}break;
			case '/': {
				DisplayImage(vram, x, ty, chromakey, divide);

				x -= 5;
			}break;
			case '*': {
				DisplayImage(vram, x, ty, chromakey, mult);

				x -= 10;
			}break;
			case '%': {
				DisplayImage(vram, x, ty, chromakey, per_sign);

				x -= 10;
			}break;
		}
	}
}

void DrawStringLR(uint32_t* vram, int tx, int ty, uint32_t chromakey, std::string str) {
	int i, x = tx;
	for (i = 0; i < str.length(); i++) {
		char cc = str[i];

		x += num_one->width;

		if (cc == '+' || cc == '-' || cc == '/') {
			x += 8;
		}

		if (cc == '*') {
			x += 8;
		}

		switch (cc) {
		case '0': {
			DisplayImage(vram, x, ty, chromakey, num_zero);
		}break;
		case '1': {
			DisplayImage(vram, x, ty, chromakey, num_one);
		}break;
		case '2': {
			DisplayImage(vram, x, ty, chromakey, num_two);
		}break;
		case '3': {
			DisplayImage(vram, x, ty, chromakey, num_three);
		}break;
		case '4': {
			DisplayImage(vram, x, ty, chromakey, num_four);
		}break;
		case '5': {
			DisplayImage(vram, x, ty, chromakey, num_five);
		}break;
		case '6': {
			DisplayImage(vram, x, ty, chromakey, num_six);
		}break;
		case '7': {
			DisplayImage(vram, x, ty, chromakey, num_seven);
		}break;
		case '8': {
			DisplayImage(vram, x, ty, chromakey, num_eight);
		}break;
		case '9': {
			DisplayImage(vram, x, ty, chromakey, num_nine);
		}break;
		case 'A': {
			DisplayImage(vram, x, ty, chromakey, a);
		}break;
		case 'B': {
			DisplayImage(vram, x, ty, chromakey, b);
		}break;
		case 'C': {
			DisplayImage(vram, x, ty, chromakey, c);
		}break;
		case 'D': {
			DisplayImage(vram, x, ty, chromakey, d);
		}break;
		case 'E': {
			DisplayImage(vram, x, ty, chromakey, e);
		}break;
		case 'F': {
			DisplayImage(vram, x, ty, chromakey, f);
		}break;
		case 'G': {
			DisplayImage(vram, x, ty, chromakey, g);
		}break;
		case 'H': {
			DisplayImage(vram, x, ty, chromakey, h);
		}break;
		case 'I': {
			DisplayImage(vram, x, ty, chromakey, ii);
		}break;
		case 'J': {
			DisplayImage(vram, x, ty, chromakey, j);
		}break;
		case 'K': {
			DisplayImage(vram, x, ty, chromakey, k);
		}break;
		case 'L': {
			DisplayImage(vram, x, ty, chromakey, l);
		}break;
		case 'M': {
			DisplayImage(vram, x, ty, chromakey, m);
		}break;
		case 'N': {
			DisplayImage(vram, x, ty, chromakey, n);
		}break;
		case 'O': {
			DisplayImage(vram, x, ty, chromakey, o);
		}break;
		case 'P': {
			DisplayImage(vram, x, ty, chromakey, p);
		}break;
		case 'Q': {
			DisplayImage(vram, x, ty, chromakey, q);
		}break;
		case 'R': {
			DisplayImage(vram, x, ty, chromakey, r);
		}break;
		case 'S': {
			DisplayImage(vram, x, ty, chromakey, s);
		}break;
		case 'T': {
			DisplayImage(vram, x, ty, chromakey, t);
		}break;
		case 'U': {
			DisplayImage(vram, x, ty, chromakey, u);
		}break;
		case 'V': {
			DisplayImage(vram, x, ty, chromakey, v);
		}break;
		case 'W': {
			DisplayImage(vram, x, ty, chromakey, w);
		}break;
		case 'X': {
			DisplayImage(vram, x, ty, chromakey, xx);
		}break;
		case 'Y': {
			DisplayImage(vram, x, ty, chromakey, y);
		}break;
		case 'Z': {
			DisplayImage(vram, x, ty, chromakey, z);
		}break;
		case '.': {
			DisplayImage(vram, x, ty, chromakey, decimal);
		}break;
		case '+': {
			DisplayImage(vram, x, ty, chromakey, plus);

			x += 5;
		}break;
		case '-': {
			DisplayImage(vram, x, ty, chromakey, minus);

			x += 5;
		}break;
		case '/': {
			DisplayImage(vram, x, ty, chromakey, divide);

			x += 5;
		}break;
		case '*': {
			DisplayImage(vram, x, ty, chromakey, mult);

			x += 10;
		}break;
		case '%': {
			DisplayImage(vram, x, ty, chromakey, per_sign);

			x += 10;
		}break;
		}
	}
}

void DrawOperator(uint32_t* vram, int tx, int ty, Operator op, uint32_t chromakey, Image* image) {
	switch (op) {
		case OP_ADD: {
			DisplayImage(vram, tx, ty, chromakey, add);
		}break;
		case OP_SUB: {
			DisplayImage(vram, tx, ty, chromakey, sub);
		}break;
		case OP_MUL: {
			DisplayImage(vram, tx, ty, chromakey, mul);
		}break;
		case OP_DIV: {
			DisplayImage(vram, tx, ty, chromakey, divv);
		}break;
		case OP_PER: {
			DisplayImage(vram, tx, ty, chromakey, per);
		}break;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow) {

	AllocConsole();
	FILE* consoleStream;
	freopen_s(&consoleStream, "CONOUT$", "w", stdout);
	freopen_s(&consoleStream, "CONOUT$", "w", stderr);

	const wchar_t window_class_name[] = L"My Window Class";
	static WNDCLASS window_class = { 0 };
	window_class.lpfnWndProc = WindowProcessMessage;
	window_class.hInstance = hInstance;
	window_class.lpszClassName = (LPCWSTR)window_class_name;
	RegisterClass(&window_class);

	Expr* expr = new Expr;

	std::string func, op1 = "0", op2 = "0"; std::vector<std::string> trace; int count = 0;

	FrameBuf* frame_buffer = new FrameBuf;

	frame_buffer->width = WIDTH;
	frame_buffer->height = HEIGHT;
	frame_buffer->vram = (uint32_t*)malloc(sizeof(uint32_t) * frame_buffer->width * frame_buffer->height);

	bool select_op1 = true, can_use_decimal = true, switched_ops = false, select_calc = true;

	int x = 10, y = 420;

	Init();

	timerInit();

	/*Initialize Bitmap Header Info*/
	frame_bitmap_info.bmiHeader.biSize = sizeof(frame_bitmap_info.bmiHeader);
	frame_bitmap_info.bmiHeader.biPlanes = 1;
	frame_bitmap_info.bmiHeader.biBitCount = 32;
	frame_bitmap_info.bmiHeader.biCompression = BI_RGB;
	frame_device_context = CreateCompatibleDC(0);

	static HWND window_handle;
	window_handle = CreateWindow((LPCWSTR)window_class_name, (LPCWSTR)L"Calculatrice", WS_OVERLAPPEDWINDOW |
		CW_USEDEFAULT | CW_USEDEFAULT | WS_VISIBLE, 400, 100,
		WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

	if (window_handle == NULL) {
		return -1;
	}

	frame_bitmap_info.bmiHeader.biWidth = WIDTH;
	frame_bitmap_info.bmiHeader.biHeight = HEIGHT;

	if (frame_bitmap) DeleteObject(frame_bitmap);
	frame_bitmap = CreateDIBSection(NULL, &frame_bitmap_info, DIB_RGB_COLORS, (void**)&frame_buffer->vram, 0, 0);
	SelectObject(frame_device_context, frame_bitmap);

	float drawInterval = 1000.00f / 60.00f;
	float delta = 0.0f;
	long lastTime = osGetSystemTimeMS();
	long currentTime;
	int timer = 0;
	int drawCount = 0;

	while (!quit) {
		static MSG message = { 0 };
		while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&message);
		}

		currentTime = osGetSystemTimeMS();

		delta += (currentTime - lastTime) / drawInterval;
		timer += (currentTime - lastTime);

		lastTime = currentTime;

		// printf("%d\n",drawCount);

		if (delta >= 1) {
			Fill(frame_buffer->vram, WIDTH, HEIGHT, RGB_32(235,235,230));

			if (select_calc) {

				DisplayImage(frame_buffer->vram, 10, 460, 0, calc_1);
				DisplayImage(frame_buffer->vram, 180, 460, 0, trace_2);

				DisplayImage(frame_buffer->vram, 10, 50, 0, zero);
				DisplayImage(frame_buffer->vram, 135, 50, 0, period);
				DisplayImage(frame_buffer->vram, 10, 115, 0, one);
				DisplayImage(frame_buffer->vram, 70, 115, 0, two);
				DisplayImage(frame_buffer->vram, 135, 115, 0, three);
				DisplayImage(frame_buffer->vram, 10, 180, 0, four);
				DisplayImage(frame_buffer->vram, 70, 180, 0, five);
				DisplayImage(frame_buffer->vram, 135, 180, 0, six);
				DisplayImage(frame_buffer->vram, 10, 245, 0, seven);
				DisplayImage(frame_buffer->vram, 70, 245, 0, eight);
				DisplayImage(frame_buffer->vram, 135, 245, 0, nine);
				DisplayImage(frame_buffer->vram, 230, 50, 0, equal);
				DisplayImage(frame_buffer->vram, 295, 50, 0, per);
				DisplayImage(frame_buffer->vram, 230, 115, 0, mul);
				DisplayImage(frame_buffer->vram, 295, 115, 0, divv);
				DisplayImage(frame_buffer->vram, 230, 180, 0, add);
				DisplayImage(frame_buffer->vram, 295, 180, 0, sub);
				DisplayImage(frame_buffer->vram, 230, 245, 0, clear);
				DisplayImage(frame_buffer->vram, 295, 245, 0, ce);

				DisplayImage(frame_buffer->vram, 10, 320, 0, bar);
				DisplayImage(frame_buffer->vram, 10, 385, 0, result);

				DrawString(frame_buffer->vram, 350, 385, 0, std::to_string(expr->result));

				if (input->zero_pressed) {
					func.push_back('0');
				}

				if (input->one_pressed) {
					func.push_back('1');
				}

				if (input->two_pressed) {
					func.push_back('2');
				}

				if (input->three_pressed) {
					func.push_back('3');
				}

				if (input->four_pressed) {
					func.push_back('4');
				}

				if (input->five_pressed) {
					func.push_back('5');
				}

				if (input->six_pressed) {
					func.push_back('6');
				}

				if (input->seven_pressed) {
					func.push_back('7');
				}

				if (input->eight_pressed) {
					func.push_back('8');
				}

				if (input->nine_pressed) {
					func.push_back('9');
				}

				if (!string_has_operator(func) || func[0] == '-' || curr_op_not_minus(func)){
					if (input->add_pressed) {
						func.push_back('+');
						can_use_decimal = true;
						switched_ops = true;
					}

					if (input->mul_pressed) {
						func.push_back('*');
						can_use_decimal = true;
						switched_ops = true;
					}

					if (input->sub_pressed) {
						func.push_back('-');
						can_use_decimal = true;
						switched_ops = true;
					}

					if (input->div_pressed) {
						func.push_back('/');
						can_use_decimal = true;
						switched_ops = true;
					}

					if (input->per_pressed) {
						func.push_back('%');
						can_use_decimal = true;
						switched_ops = true;
					}
				}
				if (input->period_pressed) {

					if (can_use_decimal == true) {
						func.push_back('.');
						can_use_decimal = false;
					}
				}

				if (input->ce_pressed) {
					func.pop_back();
				}

				if (input->clear_pressed) {
					func.clear();
					trace.clear();
					expr->result = 0;
					can_use_decimal = true;
				}

				if (input->equal_pressed && string_has_operator(func)) {

					trace.push_back("IF STRING HAS OP");
					trace.push_back("AND");
					trace.push_back("IF EQUAL PRESSED");

					ParseFunc(func, op1, op2, trace);

					std::cout << "op1: " << op1 << std::endl;
					std::cout << "op2: " << op2 << std::endl;

					trace.push_back("EXEC PARSE FUNC");
					trace.push_back("IF STRING HAS OP");
					trace.push_back("FOR I EQ 1 TO STR.LEN");

					trace.push_back("OP1 EQ " + op1);
					trace.push_back("OP2 EQ " + op2);

					expr->operand1 = StrToOperand(op1);
					expr->operand2 = StrToOperand(op2);

					std::cout << "exp op1: " << expr->operand1 << std::endl;
					std::cout << "exp op2: " << expr->operand2 << std::endl;

					trace.push_back("EXEC STRTOOPERAND FUNC OP1");
					trace.push_back("EXEC STRTOOPERAND FUNC OP2");

					trace.push_back("FOR I EQ 1 TO STR.LEN");
					int i;
					for (i = 0; i < func.length(); i++) {
						trace.push_back("SWITCH STR OF I");
					}

					expr->op = GetOperatorFromString(func);

					trace.push_back("SWITCH OPERAND");

					switch (expr->op) {
						case OP_ADD: {
							trace.push_back("OPERAND EQ +");
						}break;
						case OP_SUB: {
							trace.push_back("OPERAND EQ -");
						}break;
						case OP_MUL: {
							trace.push_back("OPERAND EQ *");
						}break;
						case OP_DIV: {
							trace.push_back("OPERAND EQ /");
						}break;
						case OP_PER: {
							trace.push_back("OPERAND EQ %");
						}break;
					}

					trace.push_back("EXEC GETOPERATORFROMSTRING FUNC");

					CalculateResult(expr);

					trace.push_back("SWTICH OPERAND");
					trace.push_back("EXEC CALCULATERESULT FUNC");

					func = std::to_string(expr->result);

					op1.clear(); op2.clear();
				}

				if (switched_ops) {
					can_use_decimal = true;
				}

				DrawString(frame_buffer->vram, 320, 330, 0, func);
			}
			else {
				DisplayImage(frame_buffer->vram, 10, 460, 0, calc_2);
				DisplayImage(frame_buffer->vram, 180, 460, 0, trace_1);

				if (trace_index < 0) {
					trace_index = 0;
				}

				if (trace_index >= trace.size()) {
					trace_index = trace.size() - 1;
				}

				int i;
				for (i = trace_index; i < trace.size(); i++) {
					DrawStringLR(frame_buffer->vram, x - 25, y, 0, std::to_string(i));
					DrawStringLR(frame_buffer->vram, x + 20, y, 0, trace[i]);

					y -= 30;
				}

				y = 420;
			}

			if (input->calc_pressed) {
				select_calc = true;
			}

			if (input->trace_pressed) {
				select_calc = false;
			}

			BlitToScreen(window_handle);

			input->Clear();

			drawCount++;
			delta--;
		}


		if (timer >= 1000) {
			drawCount = 0;
			timer = 0;
		}

	}

	Cleanup();

	delete expr;
	delete frame_buffer;

	return 0;
}

LRESULT CALLBACK WindowProcessMessage(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {
	case WM_QUIT:
	case WM_DESTROY: {
		quit = TRUE;
	}break;
	case WM_KEYDOWN: {
		if (wParam == W_PRESSED) {
			trace_index--;
		}
		if (wParam == S_PRESSED) {
			trace_index++;
		}
	}break;
	case WM_KILLFOCUS: {

	} break;
	case WM_CREATE: {
	}break;

	case WM_SETFOCUS:

	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_LBUTTONDOWN: {
		int x = LOWORD(lParam);
		int y = HEIGHT - HIWORD(lParam);

		//std::cout << "x = " << x << std::endl;
		//std::cout << "y = " << y << std::endl;
		//std::cout << "" << y << std::endl;

		if (x >= 135 && y >= 50 && x < 135 + two->width && y < 50 + two->height) {
			std::cout << "Decimal Clicked!" << std::endl;
			input->ClickPeriod();
		}

		if (x >= 10 && y >= 50 && x < 10 + zero->width && y < 50 + zero->height) {
			std::cout << "Zero Clicked!" << std::endl;
			input->ClickZero();
		}
		if (x >= 10 && y >= 115 && x < 10 + one->width && y < 115 + one->height) {
			std::cout << "One Clicked!" << std::endl;
			input->ClickOne();
		}

		if (x >= 70 && y >= 115 && x < 70 + two->width && y < 115 + two->height) {
			std::cout << "Two Clicked!" << std::endl;
			input->ClickTwo();
		}
	
		if (x >= 135 && y >= 115 && x < 135 + three->width && y < 115 + three->height) {
			std::cout << "Three Clicked!" << std::endl;
			input->ClickThree();
		}

		if (x >= 10 && y >= 180 && x < 10 + four->width && y < 180 + four->height) {
			std::cout << "Four Clicked!" << std::endl;
			input->ClickFour();
		}

		if (x >= 70 && y >= 180 && x < 70 + five->width && y < 180 + five->height) {
			std::cout << "Five Clicked!" << std::endl;
			input->ClickFive();
		}

		if (x >= 135 && y >= 180 && x < 135 + six->width && y < 180 + six->height) {
			std::cout << "Six Clicked!" << std::endl;
			input->ClickSix();
		}

		if (x >= 10 && y >= 245 && x < 10 + seven->width && y < 245 + seven->height) {
			std::cout << "Seven Clicked!" << std::endl;
			input->ClickSeven();
		}

		if (x >= 70 && y >= 245 && x < 70 + eight->width && y < 245 + eight->height) {
			std::cout << "Eight Clicked!" << std::endl;
			input->ClickEight();
		}

		if (x >= 135 && y >= 245 && x < 135 + nine->width && y < 245 + nine->height) {
			std::cout << "Nine Clicked!" << std::endl;
			input->ClickNine();
		}

		if (x >= 295 && y >= 245 && x < 295 + ce->width && y < 245 + ce->height) {
			std::cout << "CE Clicked!" << std::endl;
			input->ClickCE();
		}

		if (x >= 230 && y >= 245 && x < 230 + clear->width && y < 245 + clear->height) {
			std::cout << "Clear Clicked!" << std::endl;
			input->ClickClear();
		}

		if (x >= 230 && y >= 180 && x < 230 + add->width && y < 180 + add->height) {
			std::cout << "Add Clicked!" << std::endl;
			input->ClickAdd();
		}

		if (x >= 230 && y >= 50 && x < 230 + equal->width && y < 50 + equal->height) {
			std::cout << "Equal Clicked!" << std::endl;
			input->ClickEqual();
		}

		if (x >= 230 && y >= 115 && x < 230 + mul->width && y < 115 + mul->height) {
			std::cout << "Multiply Clicked!" << std::endl;
			input->ClickMul();
		}

		if (x >= 295 && y >= 180 && x < 295 + sub->width && y < 180 + sub->height) {
			std::cout << "Minus Clicked!" << std::endl;
			input->ClickSub();
		}

		if (x >= 295 && y >= 115 && x < 295 + divv->width && y < 115 + divv->height) {
			std::cout << "Divide Clicked!" << std::endl;
			input->ClickDiv();
		}

		if (x >= 295 && y >= 50 && x < 295 + per->width && y < 50 + per->height) {
			std::cout << "Percent Clicked!" << std::endl;
			input->ClickPer();
		}

		if (x >= 11 && y >= 467 && x < 11 + calc_1->width && y < 467 + calc_1->height) {
			std::cout << "Calculator Clicked!" << std::endl;
			input->ClickCalc();
		}

		if (x >= 182 && y >= 467 && x < 182 + calc_1->width && y < 467 + calc_1->height) {
			std::cout << "Trace Clicked!" << std::endl;
			input->ClickTrace();
		}

	}break;
	default: {
		return DefWindowProc(window_handle, message, wParam, lParam);
	}break;
	}
	return 0;
}
