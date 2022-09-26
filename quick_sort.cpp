#include <vector>
#include <iostream>

template <typename T>
class QuickSort
{
private:
    std::vector<T> m_data;

public:
    QuickSort(){};

    QuickSort(std::vector<T> data) : m_data{data}
    {
        std::cout << "before: \n";
        print_data();
        std::cout << "after: \n";
        sort();
        print_data();
    }

    ~QuickSort(){};

    void sort()
    {
        sort_helper(0, m_data.size() - 1);
    }

    void sort_helper(int front, int back)
    {
        if (front < back)
        {
            int pivot = partition(front, back);
            sort_helper(front, pivot - 1);
            sort_helper(pivot + 1, back);
        }
    }

    int partition(int front, int back)
    {
        int pivot = m_data[back];
        int i = front - 1;

        for (int j = front; j < back; j++)
        {
            if (m_data[j] < pivot)
            {
                i++;
                std::swap(m_data[i], m_data[j]);
            }
        }

        std::swap(m_data[i + 1], m_data[back]);
        return i + 1;
    }

    void insert(const std::vector<T> &vec)
    {
        for (auto ele : vec)
            m_data.push_back(ele);

        std::cout << "You have inserted: \n";

        print_data();
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
    QuickSort<int> quicksort({1, 17, 2, 19, 3, 23, 5, 29, 8, 0});
}