#!/usr/bin/env python

"""
A Python script to convert an image file into a plain-text file
of 0s and 1s.

Usage:

    python image_to_dat.py <IMAGE_FILE> <DAT_FILE>

The output file has form:

    <WIDTH_IN_PIXELS> <HEIGHT_IN_PIXELS>
    0|1 0|1 0|1 ...
    0|1 0|1 0|1 ...
    ...

0s correspond to white and 1 to black.

For example:

    5 10
    1 1 1 1 1
    0 0 0 0 0
    0 1 0 0 0
    0 0 0 1 0
    0 1 0 0 0
    0 0 0 0 0
    0 0 0 0 1
    0 0 0 0 1
    1 1 1 1 1
    0 0 0 0 0

Expanded from a code fragment at "B&W image to binary array", Stack
Overflow, https://stackoverflow.com/a/50496481
"""


import sys
import numpy as np
from PIL import Image


def image_to_dat(image_file, dat_file):
    """
    Convert an image file into a plain-text file of 0s and 1s.
    The plain-text file has a header "W H", where W and H are
    the dimensions (width and height) of the image in pixels.
    This is followed by H rows and N columns of values. Each
    value is 0 or 1, where 0 corresponds to white and 1 to
    black.

    :param image_file:
    :type image_file: str or unicode
    :param dat_file:
    :type dat_file: str or unicode
    """
    img = Image.open(image_file)
    # Convert from RGB to grayscale (0..255)
    img = img.convert('L')
    np_img = np.array(img)
    # Invert image. Each value set to 255 - value.
    # Black (0) pixels, become 1. White (255) pixels become 0.
    np_img = np.invert(np_img)
    # Set non-white (non 0) pixels to black.
    np_img[np_img > 0] = 1
    (height, width) = np_img.shape
    header = "%d %d" % (width, height)
    np.savetxt(dat_file, np_img, fmt="%d", header=header, comments="")


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: python image_to_dat.py <IMAGE_FILE> <DAT_FILE>")
        exit(1)
    image_to_dat(sys.argv[1], sys.argv[2])
