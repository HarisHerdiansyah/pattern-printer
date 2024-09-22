#include <iostream>
using namespace std;

/*
* ALGORITHM MODELS
* - Program Start
* - User input parameter for choose pattern
* - User input parameter for choose style (bold or outline)
* - Store the parameter in variables
* - Call the specific function based on input parameter
* - Let the function do the process
* - Output
* - User be able to choose to re-run the program or just exit the program
* - Program Done
*/

/**
 * * Pattern List
 * * 1 = Pyramid, 2 = Diamond, 3 = Hourglass, 4 = Pascal Triangle
 * 
 * * Style List
 * * 1 = Regular, 2 = Outline
 */

namespace input {
  int pattern() {
    int pattern;
    bool input_valid = false;

    while (!input_valid) {
      cout << "1. Piramida\n";
      cout << "2. Belah Ketupat\n";
      cout << "3. Hourglass\n";
      cout << "4. Segitiga Pascal\n";
      cout << "99. Keluar dari program\n\n";

      cout << "Pilih pola yang mau kamu cetak: ";
      cin >> pattern;
      cout << '\n';

      if ((pattern >= 1 && pattern <= 4) || pattern == 99) {
        input_valid = true;
      } else {
        cout << "Input tidak valid. Ulangi!\n\n";
      }
    }

    return pattern;
  }

  int style(int &pattern) {
    int style;
    bool input_valid = false;

    while (!input_valid) {
      cout << "1. Reguler\n";
      if (pattern != 4) cout << "2. Outline\n";
      cout << "99. Keluar dari program\n\n";

      cout << "Pilih style yang kamu mau: ";
      cin >> style;
      cout << '\n';

      if ((style >= 1 && style <= 2) || style == 99) {
        input_valid = true;
      } else {
        cout << "Input tidak valid. Ulangi!\n\n";
      }
    }

    return style;
  }

  bool re_run() {
    char re_run_code; // ? Yes (Y) or No (N)

    cout << "Mau mengulang program? ";
    cin >> re_run_code;

    return toupper(re_run_code) == 'Y'; // ? just in case user input in lowercase letter
  }
}

namespace pattern_regular {
  void pyramid(int &rows) {
    cout << "Hello Regular Pyramid" << endl << endl;
  }
  void diamond(int &rows) {
    cout << "Hello Regular Diamond" << endl << endl;
  }
  void hourglass(int &rows) {
    cout << "Hello Regular Hourglass" << endl << endl;
  }
  void pascal_triangle(int &rows) {
    cout << "Hello Regular Pascal Triangle" << endl << endl;
  }
}

namespace pattern_outline {
  void pyramid(int &rows) {
    cout << "Hello Outline Pyramid" << endl << endl;
  }
  void diamond(int &rows) {
    cout << "Hello Outline Diamond" << endl << endl;
  }
  void hourglass(int &rows) {
    cout << "Hello Outline Hourglass" << endl << endl;
  }
}

bool gate(int &pattern, int &style) {
  bool re_run;
  int rows;
  cout << "Masukkan jumlah baris yang mau kamu cetak: ";
  cin >> rows;

  switch (pattern) {
    case 1:
      if (style == 1) pattern_regular::pyramid(rows);
      else pattern_outline::pyramid(rows);
      re_run = input::re_run();
      break;
    case 2:
      if (style == 1) pattern_regular::diamond(rows);
      else pattern_outline::diamond(rows);
      re_run = input::re_run();
      break;
    case 3:
      if (style == 1) pattern_regular::hourglass(rows);
      else pattern_outline::hourglass(rows);
      re_run = input::re_run();
      break;
    case 4:
      pattern_regular::pascal_triangle(rows);
      re_run = input::re_run();
      break;
  }

  return re_run;
}

int main() {
  int pattern, style;
  bool re_run = true;

  while (re_run) {
    pattern = input::pattern();
    if (pattern == 99) break;

    style = input::style(pattern);
    if (style == 99) break;

    re_run = gate(pattern, style);
  }


  return 0;
}