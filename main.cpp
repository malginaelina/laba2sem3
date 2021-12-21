#include <gtest/gtest.h>
#include <iostream>
#include "Interface.h"

using namespace std;

int main(int argc, char **argv) {
    int test;
    cout << ("Show tests? 1 - yes, 0 - no") << endl;
    cin >> test;
    if (test == 1){
        printf("Running main() from %s\n", __FILE__);
        testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    }
    interface();
}