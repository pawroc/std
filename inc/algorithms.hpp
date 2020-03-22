#pragma once

#include <algorithm>

namespace my::std
{

template< class InputIt1, class InputIt2, class OutputIt >
OutputIt set_difference( InputIt1 first1, InputIt1 last1,
                         InputIt2 first2, InputIt2 last2,
                         OutputIt d_first )
{
    auto current1 = first1;
    auto current2 = first2;

    while (current1 != last1)
    {
        if (current2 == last2)
        {
            return ::std::copy(current1, last1, d_first);
        }

        if (*current1 < *current2)
        {
            *d_first = *current1;
            ++d_first;
            ++current1;
        }
        else
        {
            if (not (*current2 < *current1))
            {
                ++current1;
            }
            ++current2;
        }
    }
    return d_first;
}
} // namespace my::std