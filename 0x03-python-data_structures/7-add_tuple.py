#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    # Pad tuples with zeros if they are smaller than 2
    tuple_a += (0, 0)
    tuple_b += (0, 0)

    # Take only the first 2 elements of each tuple and add them
    result_tuple = (tuple_a[0] + tuple_b[0], tuple_a[1] + tuple_b[1])

    return result_tuple
