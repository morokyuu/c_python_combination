// ref
// http://y-okamoto-psy1949.la.coocan.jp/Python/misc/PythonAndC/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int ret;
    ret = system("python3 ck.py ok go");
    cout << "ret/cpp = " << ret << endl;
    cout << "Enter any character -> ";
    char c;
    cin >> c;
    return 0;
}


