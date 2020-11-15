#include <iostream>
#include <vector>

#include "findpeak.hpp"

int main()
{    
    using namespace std;
    
    std::size_t res = 0;
    ///////////////////////////////////////////////////////////
    // Test peak_index

    // peak at beginning
    std::vector<int> test_1{ 3, 2, 1 };
    res = peak_index(test_1);
    cout << "test_1 result = " << res << ", should be = " << 0 << endl; 

    // peak at odd index middle
    std::vector<int> test_2{ 1, 3, 1 };
    res = peak_index(test_2);
    cout << "test_2 result = " << res << ", should be = " << 1 << endl; 

    // peak at even index end
    std::vector<int> test_3{ 1, 2, 3 };
    res = peak_index(test_3);
    cout << "test_3 result = " << res << ", should be = " << 2 << endl;

    // peak at even index middle
    std::vector<int> test_4{ 0, 1, 3, 2 };
    res = peak_index(test_4);
    cout << "test_4 result = " << res << ", should be = " << 2 << endl;

    // peak at even index end
    std::vector<int> test_5{ 0, 1, 2, 3 };
    res = peak_index(test_5);
    cout << "test_5 result = " << res << ", should be = " << 3 << endl;

    // no peak - result undefined, just making sure it doesn't blow up
    std::vector<int> test_6{ 3, 3, 3, 3, 3 };
    res = peak_index(test_6);
    cout << "test_6 result = "<< res << ", just confirming it terminates." << endl;

}
