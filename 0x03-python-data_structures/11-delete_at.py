#!/usr/bin/python3
ef delete_at(my_list=[], idx=0):
    # Delete the item at a specific position in the list
    if idx < 0 or idx >= len(my_list):
        # If idx is negative or out of range, return the same list
        return my_list

    # Create a new list with the element at the specified index removed
    return my_list[:idx] + my_list[idx + 1:]
