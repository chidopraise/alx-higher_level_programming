#!/usr/bin/python3
"""
    Class that defines a square.

    Attributes:
        __size (int): The size of the square.
        __position (tuple): The position of the square.
"""


class Square:
    """
    Class that defines a square.

    Attributes:
        __size (int): The size of the square.
        __position (tuple): The position of the square.
    """

    def __init__(self, size=0, position=(0, 0)):
        """
        Initializes a new instance of the Square class.

        Parameters:
            size (int, optional): The size of the square (default is 0).
            position (tuple, optional): The position of the square
            (default is (0, 0)).

        Raises:
            TypeError: If size is not an integer or position
            is not a tuple of two positive integers.
            ValueError: If size is less than 0.
        """
        self.size = size
        self.position = position

    @property
    def size(self):
        """
        Getter method for the size attribute.

        Returns:
            int: The size of the square.
        """
        return self.__size

    @size.setter
    def size(self, value):
        """
        Setter method for the size attribute.

        Parameters:
            value (int): The new value for the size attribute.

        Raises:
            TypeError: If value is not an integer.
            ValueError: If value is less than 0.
        """
        if not isinstance(value, int):
            raise TypeError("size must be an integer")
        elif value < 0:
            raise ValueError("size must be >= 0")
        else:
            self.__size = value

    @property
    def position(self):
        """
        Getter method for the position attribute.

        Returns:
            tuple: The position of the square.
        """
        return self.__position

    @position.setter
    def position(self, value):
        """
        Setter method for the position attribute.

        Parameters:
            value (tuple): The new value for the position attribute.

        Raises:
            TypeError: If value is not a tuple or contains non-integer
            elements or does not have exactly 2 elements.
            ValueError: If any element in the tuple is less than 0.
        """
        if not isinstance(value, tuple) or len(value) != 2 or\
                not all(isinstance(i, int) for i in value):
            raise TypeError("position must be a tuple of 2 positive integers")
        elif any(i < 0 for i in value):
            raise ValueError("position must be a tuple of 2 positive integers")
        else:
            self.__position = value

    def area(self):
        """
        Calculates and returns the area of the square.

        Returns:
            int: The area of the square.
        """
        return self.__size ** 2

    def my_print(self):
        """
        Prints the square using the character '#'
        and considering the position attribute.
        """
        if self.__size == 0:
            print()
        else:
            for _ in range(self.__position[1]):
                print()
            for _ in range(self.__size):
                print(" " * self.__position[0] + "#" * self.__size)

    def __str__(self):
        """
        Returns a string representation of the square for printing.

        Returns:
            str: The string representation of the square.
        """
        result = ""
        if self.__size == 0:
            return result
        else:
            for _ in range(self.__position[1]):
                result += "\n"
            for _ in range(self.__size):
                result += " " * self.__position[0] + "#" * self.__size + "\n"
            return result.strip()
