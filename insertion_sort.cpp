#include <bits/stdc++.h>

class InsertionSort
{
private:
    std::vector<int> m_data;

public:
    InsertionSort()
    {
    }

    InsertionSort(std::vector<int> data)
    {
        m_data = data;
        std::cout << "before: \n";
        print_data();

        std::cout << "after: \n";
        sort();
        print_data();
    }

    ~InsertionSort() {}

    void insert(const std::vector<int> &vec)
    {
        for (auto ele : vec)
            m_data.push_back(ele);

        std::cout << "You have inserted: \n";

        print_data();
    }

    void sort()
    {
        for (int j = 1; j < m_data.size(); j++)
        {
            int i = j - 1;
            int x = m_data[j];

            while (x < m_data[i] && i > -1)
            {
                m_data[i + 1] = m_data[i];
                i = i - 1;
            }
            m_data[i + 1] = x;
        }
    }

    void print_data()
    {
        for (auto ele : m_data)
            std::cout << ele << " ";

        std::cout << "\n";
    }
};

int main()
{
    InsertionSort({1, 17, 2, 19, 3, 23, 5, 29, 8, 0});
}