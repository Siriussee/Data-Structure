// unique algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::unique, std::distance
#include <vector>    // std::vector
#include <string>
#include <sstream>

using namespace std;
int main()
{
    int N;
    cin >> N;
    string waste;
    getline(cin, waste);
    while (N--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        vector<int> vec_a, vec_b, ans;

        stringstream ss;
        ss << a;
        int temp;
        while (!ss.str().empty())
        {
            ss >> temp;
            vec_a.push_back(temp);
        }
        ss << b;
        while (!ss.str().empty())
        {
            ss >> temp;
            vec_b.push_back(temp);
        }
        /*
        for (int i = 0; i < a.length(); i += 2)
            vec_a.push_back(a[i] - '0');
        for (int i = 0; i < b.length(); i += 2)
            vec_b.push_back(b[i] - '0');*/

        auto it = unique(vec_a.begin(), vec_a.end());
        vec_a.resize(distance(vec_a.begin(), it));

        it = unique(vec_b.begin(), vec_b.end());
        vec_b.resize(distance(vec_b.begin(), it));

        sort(vec_a.begin(), vec_a.end());
        sort(vec_b.begin(), vec_b.end());

        for (auto it = vec_a.begin(); it != vec_a.end(); ++it)
        {
            //if (!binSearch(vec_b, *it))
            if (find(vec_b.begin(), vec_b.end(), *it) == vec_b.end())
                ans.push_back(*it);
        }
        if (!ans.empty())
        {
            for (int i = 0; i < ans.size() - 1; ++i)
                cout << ans[i] << " ";

            cout << ans[ans.size() - 1];
        }
        cout << endl;
        cin.get();
    }

    return 0;
}
