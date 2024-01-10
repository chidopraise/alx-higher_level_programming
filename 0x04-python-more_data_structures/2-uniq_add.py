#!/usr/bin/python3
def uniq_add(my_list=[]):
    # Use set to keep track of unique integers
    unique_set = set()

    # Iterate through the list and add unique integers to the set
    for num in my_list:
        unique_set.add(num)

    # Sum up the unique integers in the set
    result = sum(unique_set)

    return result
