#!/usr/bin/python3

"""
This module contains the Island perimeter
function
"""



def look_around(grid, row, col):
    """This function checks around a given cell.

    Args:
        grid(`list`): List of list of integers
        row(`int`): row number of the cell
        col(`int`): col number of the cell
    """


def island_perimeter(grid):
    """This function returns the perimeter of the island described in grid.

    Args:
        grid(`list`): A 2D list of list of integers.

    Returns:
        (int): Perimeter of the island
    """

    perimeter = 0
    col_count = len(grid[0]) if grid else 0
    row_count = len(grid)

    for i in range(row_count):

