#include<iostream>
#include<vector>
#include<cassert>
#include<random>
#include<algorithm>
#include<functional>
#include "quick_sort.h"

#include "gtest/gtest.h"

template<typename _Iter>
std::ostream& PrintRange(_Iter start, _Iter end, std::ostream& os = std::cout)
{
    _Iter itr;
    for (itr = start; itr != (end + 1); ++itr)
    {
        os << (*itr) << " ";
    }
        os  << "\n ";

    return os;
}



TEST(SortingTest, SimplegivenVectorLesson) {
    std::vector<int> to_sort = { 10, 7, 12, 6, 3, 2, 8 };
    //std::vector<int> to_sort = { 8, 10, 7, 12 };
    std::cout <<"Iterator : "<< &*begin(to_sort) <<"\n";
    std::cout <<"Pointer : " <<  &to_sort << "\n";
    std::vector<int> sorted = { 2,3 ,6 ,7 ,8 ,10 ,12 };
    std::cout << &sorted << "\n";
    SortAlg::QuickSort(begin(to_sort), std::prev(end(to_sort)));
    EXPECT_EQ(to_sort, sorted);
}



TEST(SortingTest, SimplegivenVector){
    std::vector<int> to_sort = {4,6,5,2,3,1};
    std::vector<int> sorted =  {1,2,3,4,5,6};

    SortAlg::QuickSort(begin(to_sort),std::prev(end(to_sort)));
    EXPECT_EQ(to_sort, sorted);
}

TEST(SortingTest, RandomTest) {

    for (int idx = 0; idx < 100000; idx++) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(-100, 100);
        std::vector<int> v;
        generate_n(std::back_inserter(v), 200, bind(dist, gen));
        std::vector<int> v1 = v;

        std::sort(v1.begin(), v1.end());  //sort using standart function from "algorithm"
        SortAlg::QuickSort(begin(v), std::prev(end(v)));
        EXPECT_EQ(v1, v);
    
    }
    
}

int main(int argc, char* argv ) {
    
   testing::InitGoogleTest(&argc,&argv);
   return RUN_ALL_TESTS();
   
   return 0;
}