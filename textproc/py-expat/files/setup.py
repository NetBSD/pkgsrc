# $NetBSD: setup.py,v 1.1.1.1 2002/10/16 16:45:56 tsarna Exp $

import distutils
from distutils.core import setup, Extension

expatprefix = '@EXPATPREFIX@'
expatincl = expatprefix + '/include'
expatlib = expatprefix + '/lib'
expatrtprefix = '@EXPATPREFIX@'
expatrtlib = expatrtprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'pyexpat',
			['Modules/pyexpat.c'],
                        define_macros=[('HAVE_EXPAT_H', None)],
			include_dirs=[expatincl],
			library_dirs=[expatlib],
			runtime_library_dirs=[expatrtlib],
			libraries=['expat']
		)
	]
)
