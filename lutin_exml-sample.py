#!/usr/bin/python
import realog.debug as debug
import lutin.tools as tools

def get_type():
	return "BINARY"

def get_sub_type():
	return "SAMPLE"

def get_desc():
	return "e-xml sample"

def get_licence():
	return "MPL-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return "authors.txt"

def configure(target, my_module):
	my_module.add_src_file([
	    'sample/main.cpp',
	    'sample/read.cpp',
	    'sample/write.cpp'
	    ])
	my_module.add_depend([
	    'exml',
	    'test-debug'
	    ])
	my_module.copy_path('sample/read.xml')
	return True

