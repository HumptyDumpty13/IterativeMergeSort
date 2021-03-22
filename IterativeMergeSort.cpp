#include <iostream>
#include <queue>
#include <vector>
#include <utility>

std::vector<int> Merge(std::vector<int> l, std::vector<int> r, long int& count) {
    std::vector<int> result;
    unsigned long left = 0;
    unsigned long right = 0;
    for (unsigned int i = 0; i < l.size() + r.size(); i++)
    {
        if (left < l.size() && right < r.size())
            if (l[left] > r[right])
            {
                result.push_back(r[right]);
                ++right;
                count +=l.size() - left;
            }
            else //if int go for 
            {
                result.push_back(l[left]);
                ++left;
            }
        else
            if (right < r.size())
            {
                result.push_back(r[right]);
                ++right;
            }
            else
            {
                result.push_back(l[left]);
                ++left;
            }
    }
        //while(left < l.size() && right < r.size()) {
        //    if (l[left] > r[right])
        //    {
        //        result.push_back(r[right]);
        //        ++right;
        //        count += (l.size() - left);
        //    }
        //    else
        //    {
        //        result.push_back(l[left]);
        //        ++left;
        //    }
        //}
        //    while(right < r.size())
        //    {
        //        result.push_back(r[right]);
        //        ++right;
        //    }
        //    //else
        //    while(left< l.size())
        //    {
        //        result.push_back(l[left]);
        //        ++left;
        //    }

    return result;
}



long int IterativeMergeSort(std::vector<int>& v, long int& counter) {
    std::queue<std::vector<int>> q;
    for (int i = 0; i < v.size(); ++i) {
        q.push({ v[i] });
    }
    double x = q.size() - 1;
    unsigned int* answer = reinterpret_cast<unsigned int*>(&x);
    ++answer;
    *answer = 1 << (((*answer & 0x7FF00000) >> 20) - 1022);
        for (size_t t = q.size(); t < *answer; ++t) {
            q.push({ 2147483647 });
        }
    while (q.size() > 1) {
        auto first = q.front();
        q.pop();
        auto second = q.front();
        q.pop();
        q.push(Merge(first, second, counter));
    }
    return counter;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    long int counter = 0;

    IterativeMergeSort(v, counter);
    std::cout << counter;

    return 0;
}


