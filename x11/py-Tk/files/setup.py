# $NetBSD: setup.py,v 1.6 2015/07/04 16:18:42 joerg Exp $

import distutils
from distutils.core import setup, Extension

blprefix= '@BLPREFIX@'
blincl = blprefix + '/include'
bllib = blprefix + '/lib'
tclrtprefix = '@TCLRTPREFIX@'
tclrtlib = tclrtprefix + '/lib'
tclincl = tclrtprefix + '/include/tcl/generic'
tkrtprefix = '@TKRTPREFIX@'
tkrtlib = tkrtprefix + '/lib'
x11prefix = '@X11BASE@'
x11incl = x11prefix + '/include'
x11lib = x11prefix + '/lib'
x11rtprefix = '@X11BASE@'
x11rtlib = x11rtprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'_tkinter',
			['Modules/_tkinter.c', 'Modules/tkappinit.c'],
			define_macros=[('WITH_APPINIT', None)],
			include_dirs=[blincl, tclincl, x11incl],
			library_dirs=[bllib, x11lib],
			runtime_library_dirs=[tclrtlib, tkrtlib, x11rtlib],
			libraries=['tk', 'tcl', @X11LIB@]
		)
	]
)
