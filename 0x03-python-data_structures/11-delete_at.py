#!/usr/bin/python3
def delete_at(my_list=[], idx=0):
    # Delete the item at a specific position in the list
    if 0 <= idx < len(my_list):
        # If idx is within the valid range, delete the element at idx
        del my_list[idx]
    return my_list
