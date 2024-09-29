#include <iostream>
#include <vector>
using namespace std;

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

  bool is_re_run() {
    char confirmation_code; // ? Yes (Y) or No (N)

    cout << "Mau mengulang program (Y/y: Ya, N/n: Tidak) ? ";
    cin >> confirmation_code;

    return toupper(confirmation_code) == 'Y'; // ? just in case user input in lowercase letter
  }
}

namespace pattern_regular {
  void pyramid(int &rows) {
    cout << "Hello Regular Pyramid" << endl << endl;
  }
  void diamond(int &rows) {
    int n = rows / 2;
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1 - i; j++) {
        cout << " ";
      }
      for (int m = 1; m <= 2 * i - 1; m++) {
        cout << "*";
      }
      cout << endl;
    }
    for (int i = n; i > 0; i--) {
      for (int k = 0; k <= n + 1 - i; k++) {
        cout << " ";
      }
      for (int j = 1; j <= 2 * i - 1; j++) {
        cout << "*";
      }
      cout << endl;
    }
  }
  void hourglass(int &rows) {
    cout << "Hello Regular Hourglass" << endl << endl;
  }
  void pascal_triangle(int &rows) {
    vector<vector<int>> result = {};

    for (int i = 0; i < rows; i++) {
      if (result.size() == 0) {
        result.push_back({1});
      } else {
        vector<int> prev = result[i - 1];
        vector<int> new_row = {1, 1};
        for (int j = 0; j < prev.size() - 1; j++) {
            int sum = prev[j] + prev[j + 1];
            new_row.insert(new_row.begin() + 1, sum);
        }
        result.push_back(new_row);
      }
    }

    for (int i = 0; i < result.size(); i++) {
      for (int k = result.size() - 1; k > i; k--) {
        cout << " ";
      }
      for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
      }
      cout << endl;
    }
  }
}

namespace pattern_outline {
  void pyramid(int &rows) {
    cout << "Hello Outline Pyramid" << endl << endl;
  }
  void diamond(int &rows) {
    int n = rows / 2;
    for (int i = 1; i <= n + 1; i++){
        for (int j = i; j < n + 1; j++){
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++){
            if (k == 1 || k == (2 * i - 1)){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = n; i > 0; i--){
        for (int j = i; j < n + 1; j++){
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++){
            if (k == 1 || k == (2 * i - 1)){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
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
      re_run = input::is_re_run();
      break;
    case 2:
      if (style == 1) pattern_regular::diamond(rows);
      else pattern_outline::diamond(rows);
      re_run = input::is_re_run();
      break;
    case 3:
      if (style == 1) pattern_regular::hourglass(rows);
      else pattern_outline::hourglass(rows);
      re_run = input::is_re_run();
      break;
    case 4:
      pattern_regular::pascal_triangle(rows);
      re_run = input::is_re_run();
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