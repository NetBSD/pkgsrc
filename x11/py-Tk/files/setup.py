# $NetBSD: setup.py,v 1.1 2002/01/28 17:34:30 drochner Exp $

import distutils
from distutils.core import setup, Extension

tclprefix = '@TCLPREFIX@'
tclincl = tclprefix + '/include'
tcllib = tclprefix + '/lib'

x11prefix = '@X11PREFIX@'
x11incl = x11prefix + '/include'
x11lib = x11prefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'_tkinter',
			['Modules/_tkinter.c', 'Modules/tkappinit.c'],
			define_macros=[('WITH_APPINIT', None)],
			include_dirs=[tclincl, x11incl],
			library_dirs=[tcllib, x11lib],
			runtime_library_dirs=[tcllib, x11lib],
			libraries=['tk83', 'tcl83', 'X11']
		)
	]
)
