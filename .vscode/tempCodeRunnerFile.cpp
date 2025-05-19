#include <iostream>
using namespace std;

int main() {
  
  int operand1 = 3;
  int operand2 = 2;
  cout << "operand1 = " << operand1 << " , operand2 = " << operand2 << endl;
  cout << "operand1 & operand2 = " << (operand1 & operand2) << endl;
  cout << "operand1 | operand2 = " << (operand1 | operand2 )<< endl;
  cout << "operand1 ^ operand2 = " << (operand1 ^ operand2) << endl;
  
  return 0;
}