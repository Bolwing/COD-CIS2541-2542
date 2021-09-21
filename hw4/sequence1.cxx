// FILE: sequence1.cxx
// CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)
// INVARIANT for the sequence ADT:
//   1. The number of items in the sequence is in the member variable used;
//   2. For an empty sequence, we do not care what is stored in any of data;
//      for a non-empty sequence the items in the sequence are stored in
//      sequence order from data[0] through data[used-1], and we don't care
//      what's in the rest of data.
//   3. If there is a current item, then that item is in data[current_index];
//      Otherwise, current_index equals used.

#include <cassert>  // Provides assert
#include "sequence1.h"
#include <string>
using namespace std;

namespace main_savitch_3
{
    template<typename value_type>
    sequence<value_type>::sequence()
    {
        used = 0;
        current_index = 0;
    }
    template<typename value_type>
    void sequence<value_type>::start()
    {
        current_index = 0;
    }
    template<typename value_type>
    void sequence<value_type>::advance()
        // Library facilities used: assert.h
    {
        assert(is_item());
        current_index++;
    }
    template<typename value_type>
    void sequence<value_type>::insert(const value_type& entry)
        // Library facilities used: assert.h
    {
        size_type i;

        // Check the precondition
        assert(size() < CAPACITY);

        // If there is no current item,
        // then set current_index to the front so that
        // the new entry will be placed at the front of the array.
        if (!is_item())
            current_index = 0;

        // Shift other items over, and insert the new entry at current_index
        for (i = used; i > current_index; i--)
            data[i] = data[i - 1];
        data[current_index] = entry;
        used++;
    }
    template<typename value_type>
    void sequence<value_type>::attach(const value_type& entry)
        // Library facilities used: assert.h
    {
        size_type i;

        // Check the precondition
        assert(size() < CAPACITY);

        if (!is_item()) // There is no current item, so insert at end
            data[current_index] = entry;
        else // There is a current item, so move items over to make room
        {
            for (i = used; i > current_index + 1; i--)
                data[i] = data[i - 1];
            data[current_index + 1] = entry;
            current_index++;
        }

        used++;
    }

    template<typename value_type>
    void sequence<value_type>::remove_current()
        // Library facilties used: assert.h
    {
        size_type i;

        assert(is_item());

        for (i = current_index + 1; i < used; i++)
            data[i - 1] = data[i];

        used--;
    }

    template<typename value_type>
    size_t sequence<value_type>::size() const
    {
        return used;
    }

    template<typename value_type>
    bool sequence<value_type>::is_item() const
    {
        return (current_index < used);
    }

    template<typename value_type>
    value_type sequence<value_type>::current() const
        // Library facilities used: assert.h
    {
        assert(is_item());
        return data[current_index];
    }

    template class sequence<int>;
    template class sequence<float>;
    template class sequence<double>;
    template class sequence<string>;
}
