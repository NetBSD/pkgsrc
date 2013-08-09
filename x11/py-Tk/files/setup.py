# $NetBSD: setup.py,v 1.4 2013/08/09 15:18:58 adam Exp $

import distutils
from distutils.core import setup, Extension

blprefix= '@BLPREFIX@'
blincl = blprefix + '/include'
bllib = blprefix + '/lib'
tclrtprefix = '@TCLRTPREFIX@'
tclrtlib = tclrtprefix + '/lib'
tkrtprefix = '@TKRTPREFIX@'
tkrtlib = tkrtprefix + '/lib'
x11prefix = '@X11PREFIX@'
x11incl = x11prefix + '/include'
x11lib = x11prefix + '/lib'
x11rtprefix = '@X11RTPREFIX@'
x11rtlib = x11rtprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'_tkinter',
			['Modules/_tkinter.c', 'Modules/tkappinit.c'],
			define_macros=[('WITH_APPINIT', None)],
			include_dirs=[blincl, x11incl],
			library_dirs=[bllib, x11lib],
			runtime_library_dirs=[tclrtlib, tkrtlib, x11rtlib],
			libraries=['tk', 'tcl', @X11LIB@]
		)
	]
)
