#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr = {2,7,11,15};
    int size = arr.size();
    int target = 9;
    int ans1 = 0;
    int ans2 = 0;
    bool found = false;

    for (int count1 = 0; count1 < size - 1 && !found; ++count1)
    {
        for (int count2 = count1 + 1; count2 < size && !found; ++count2)
        {
            if ((arr[count1] + arr[count2]) == target)
            {
                ans1 = count1;
                ans2 = count2;
                found = true;
            }
        }
    }

    cout << ans1 << ' ' << ans2;

    system("pause");
    return 0;
}