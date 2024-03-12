#ifndef INPUT_H
#define INPUT_H

#define W_PRESSED          87
#define S_PRESSED          83

typedef struct Input {
	bool zero_pressed, one_pressed, two_pressed, three_pressed;
	bool four_pressed, five_pressed, six_pressed;
	bool seven_pressed, eight_pressed, nine_pressed;
	bool period_pressed, add_pressed, sub_pressed, mul_pressed;
	bool div_pressed, per_pressed, clear_pressed, ce_pressed, equal_pressed;
	bool calc_pressed, trace_pressed;

	public:
		Input() {
			zero_pressed = false; one_pressed = false; two_pressed = false; three_pressed = false;
			four_pressed = false; five_pressed = false; six_pressed = false; calc_pressed = true; trace_pressed = false;
			seven_pressed = false; eight_pressed = false; nine_pressed = false; equal_pressed = false;
			period_pressed = false; add_pressed = false; sub_pressed = false; mul_pressed = false;
			div_pressed = false; per_pressed = false; clear_pressed = false; ce_pressed = false;
		}

		void Clear() {
			zero_pressed = false; one_pressed = false; two_pressed = false; three_pressed = false;
			four_pressed = false; five_pressed = false; six_pressed = false;  calc_pressed = false; trace_pressed = false;
			seven_pressed = false; eight_pressed = false; nine_pressed = false; equal_pressed = false;
			period_pressed = false; add_pressed = false; sub_pressed = false; mul_pressed = false;
			div_pressed = false; per_pressed = false; clear_pressed = false; ce_pressed = false;
		}

		void ClickZero() {
			zero_pressed = true;
		}

		void ClickOne() {
			one_pressed = true;
		}

		void ClickTwo() {
			two_pressed = true;
		}

		void ClickThree() {
			three_pressed = true;
		}

		void ClickFour() {
			four_pressed = true;
		}

		void ClickFive() {
			five_pressed = true;
		}

		void ClickSix() {
			six_pressed = true;
		}

		void ClickSeven() {
			seven_pressed = true;
		}

		void ClickEight() {
			eight_pressed = true;
		}

		void ClickNine() {
			nine_pressed = true;
		}

		void ClickPeriod() {
			period_pressed = true;
		}

		void ClickMul() {
			mul_pressed = true;
		}

		void ClickDiv() {
			div_pressed = true;
		}

		void ClickAdd() {
			add_pressed = true;
		}

		void ClickSub() {
			sub_pressed = true;
		}

		void ClickEqual() {
			equal_pressed = true;
		}

		void ClickPer() {
			per_pressed = true;
		}

		void ClickClear() {
			clear_pressed = true;
		}

		void ClickCE() {
			ce_pressed = true;
		}

		void ClickCalc() {
			calc_pressed = true;
		}

		void ClickTrace() {
			trace_pressed = true;
		}
}Input;


#endif

