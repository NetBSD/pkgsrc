# $NetBSD: setup.py,v 1.5 2015/05/27 20:46:34 wiz Exp $

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
			include_dirs=[blincl, tclincl, x11incl],
			library_dirs=[bllib, x11lib],
			runtime_library_dirs=[tclrtlib, tkrtlib, x11rtlib],
			libraries=['tk', 'tcl', @X11LIB@]
		)
	]
)
