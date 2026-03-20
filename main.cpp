#include<bits/stdc++.h>

#include "Int128.h"

using namespace std;

int main() {
    Int128 a(5,1),b(1,5);
    a^=b;
    cout<<a.low;
    return 0;
}