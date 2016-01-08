#!/usr/bin/env python
#
# Python-bindings seek testing program
#
# Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
#
# Refer to AUTHORS for acknowledgements.
#
# This software is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this software.  If not, see <http://www.gnu.org/licenses/>.
#

import argparse
import os
import sys

import pyvshadow


def get_whence_string(whence):
  """Retrieves a human readable string representation of the whence."""
  if whence == os.SEEK_CUR:
    whence_string = "SEEK_CUR"
  elif whence == os.SEEK_END:
    whence_string = "SEEK_END"
  elif whence == os.SEEK_SET:
    whence_string = "SEEK_SET"
  else:
    whence_string = "UNKNOWN"
  return whence_string


def pyvshadow_test_seek_offset(
    vshadow_store, input_offset, input_whence, output_offset):

  print("Testing seek of offset: {0:d} and whence: {1:s}\t".format(
      input_offset, get_whence_string(input_whence)))

  result = True
  try:
    vshadow_store.seek(input_offset, input_whence)

    if result:
      result_offset = vshadow_store.get_offset()
      if output_offset != result_offset:
        result = False

  except Exception as exception:
    print(str(exception))
    if output_offset != -1:
      result = False

  if not result:
    print("(FAIL)")
  else:
    print("(PASS)")
  return result


def pyvshadow_test_seek(vshadow_store):
  volume_size = vshadow_store.size

  # Test: SEEK_SET offset: 0
  # Expected result: 0
  if not pyvshadow_test_seek_offset(vshadow_store, 0, os.SEEK_SET, 0):
    return False

  # Test: SEEK_SET offset: <volume_size>
  # Expected result: <volume_size>
  if not pyvshadow_test_seek_offset(
      vshadow_store, volume_size, os.SEEK_SET, volume_size):
    return False

  # Test: SEEK_SET offset: <volume_size / 5>
  # Expected result: <volume_size / 5>
  seek_offset, _ = divmod(volume_size, 5)
  if not pyvshadow_test_seek_offset(
      vshadow_store, seek_offset, os.SEEK_SET, seek_offset):
    return False

  # Test: SEEK_SET offset: <volume_size + 987>
  # Expected result: <volume_size + 987>
  seek_offset = volume_size + 987
  if not pyvshadow_test_seek_offset(
      vshadow_store, seek_offset, os.SEEK_SET, seek_offset):
    return False

  # Test: SEEK_SET offset: -987
  # Expected result: -1
  seek_offset = -987
  if not pyvshadow_test_seek_offset(
      vshadow_store, seek_offset, os.SEEK_SET, -1):
    return False

  # Test: SEEK_CUR offset: 0
  # Expected result: <volume_size + 987>
  if not pyvshadow_test_seek_offset(
      vshadow_store, 0, os.SEEK_CUR, volume_size + 987):
    return False

  # Test: SEEK_CUR offset: <-1 * (volume_size + 987)>
  # Expected result: 0
  if not pyvshadow_test_seek_offset(
      vshadow_store, -1 * (volume_size + 987), os.SEEK_CUR, 0):
    return False

  # Test: SEEK_CUR offset: <volume_size / 3>
  # Expected result: <volume_size / 3>
  seek_offset, _ = divmod(volume_size, 3)
  if not pyvshadow_test_seek_offset(
      vshadow_store, seek_offset, os.SEEK_CUR, seek_offset):
    return False

  if volume_size == 0:
    # Test: SEEK_CUR offset: <-2 * (volume_size / 3)>
    # Expected result: 0
    seek_offset, _ = divmod(volume_size, 3)
    if not pyvshadow_test_seek_offset(
        vshadow_store, -2 * seek_offset, os.SEEK_CUR, 0):
      return False

  else:
    # Test: SEEK_CUR offset: <-2 * (volume_size / 3)>
    # Expected result: -1
    seek_offset, _ = divmod(volume_size, 3)
    if not pyvshadow_test_seek_offset(
        vshadow_store, -2 * seek_offset, os.SEEK_CUR, -1):
      return False

  # Test: SEEK_END offset: 0
  # Expected result: <volume_size>
  if not pyvshadow_test_seek_offset(
      vshadow_store, 0, os.SEEK_END, volume_size):
    return False

  # Test: SEEK_END offset: <-1 * volume_size>
  # Expected result: 0
  if not pyvshadow_test_seek_offset(
      vshadow_store, -1 * volume_size, os.SEEK_END, 0):
    return False

  # Test: SEEK_END offset: <-1 * (volume_size / 4)>
  # Expected result: <volume_size - (volume_size / 4)>
  seek_offset, _ = divmod(volume_size, 4)
  if not pyvshadow_test_seek_offset(
      vshadow_store, -1 * seek_offset, os.SEEK_END, volume_size - seek_offset):
    return False

  # Test: SEEK_END offset: 542
  # Expected result: <volume_size + 542>
  if not pyvshadow_test_seek_offset(
      vshadow_store, 542, os.SEEK_END, volume_size + 542):
    return False

  # Test: SEEK_END offset: <-1 * (volume_size + 542)>
  # Expected result: -1
  if not pyvshadow_test_seek_offset(
      vshadow_store, -1 * (volume_size + 542), os.SEEK_END, -1):
    return False

  # Test: UNKNOWN (88) offset: 0
  # Expected result: -1
  if not pyvshadow_test_seek_offset(vshadow_store, 0, 88, -1):
    return False

  return True


def pyvshadow_test_seek_file(filename):
  vshadow_volume = pyvshadow.volume()

  vshadow_volume.open(filename, "r")

  result = True
  for vshadow_store in vshadow_volume.stores:
    result = pyvshadow_test_seek(vshadow_store)
    if not result:
      break

  vshadow_volume.close()

  return result


def pyvshadow_test_seek_file_object(filename):
  file_object = open(filename, "rb")
  vshadow_volume = pyvshadow.volume()

  vshadow_volume.open_file_object(file_object, "r")

  result = True
  for vshadow_store in vshadow_volume.stores:
    result = pyvshadow_test_seek(vshadow_store)
    if not result:
      break

  vshadow_volume.close()

  return result


def main():
  args_parser = argparse.ArgumentParser(description=(
      "Tests seek."))

  args_parser.add_argument(
      "source", nargs="?", action="store", metavar="FILENAME",
      default=None, help="The source filename.")

  options = args_parser.parse_args()

  if not options.source:
    print("Source value is missing.")
    print("")
    args_parser.print_help()
    print("")
    return False

  if not pyvshadow_test_seek_file(options.source):
    return False

  if not pyvshadow_test_seek_file_object(options.source):
    return False

  return True


if __name__ == "__main__":
  if not main():
    sys.exit(1)
  else:
    sys.exit(0)

