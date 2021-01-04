#pragma once

namespace SortAlg {

    //Quick sort algorithm.
    //Based on https://www.youtube.com/watch?v=ZHVk2blR45Q&t=336s
    //Dr. Rob Edwards from San Diego State University 

    template<typename _Iter>
    void QuickSort(_Iter first, _Iter last)
    {
        //step 0
        //check if the data structure has size 0
        if (first == last)
        {
            return;
        }

        _Iter It_larger_pivot = first;
        _Iter It_current_pos = first;
        _Iter iPivot = first + (std::distance(first, last) / 2);

        //step 1 - swap pivot with the last element

        std::iter_swap(iPivot, last);
        iPivot = last;

        //step 2
        //iterate trough the  data up to the pivot and swap all the elemetns 
        //smaller than pivot with the element pointed by It_larger_pivot and increment 
        //It_larger_pivot by one

        while (It_current_pos != iPivot && It_larger_pivot != iPivot)
        {
            if ((*It_current_pos) < (*iPivot))
            {
                if (It_current_pos == It_larger_pivot)
                {
                    It_larger_pivot++;
                    It_current_pos++;
                }
                else
                {
                    std::iter_swap(It_current_pos, It_larger_pivot);
                    It_larger_pivot++;
                }
            }
            else
            {
                It_current_pos++;
            }
        }

        //step 3
        //swap the pivot point with It_larger_pivot

        std::iter_swap(It_larger_pivot, iPivot);
        iPivot = It_larger_pivot;


        //step 4
        //Recursievly call the function for two parts of the data:
        //begin -> (pivot - 1)   and (pivot + 1) -> end

        if (iPivot != first)
        {
            QuickSort(first, (iPivot - 1));
        }

        if (iPivot != last)
        {
            QuickSort((iPivot + 1), last);
        }
    }
}

