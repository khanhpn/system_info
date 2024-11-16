require 'mkmf'

abort "GCC or Clang not found!" unless find_executable('clang') || find_executable('gcc')

create_makefile('system_info/system_info')
