#!/bin/sh
export XKEYSYMDB ; XKEYSYMDB=@X11BASE@/lib/X11/XKeysymDB
export XNLSPATH  ; XNLSPATH=@PREFIX@/share/netscape/nls
export XAPPLRESDIR ; XAPPLRESDIR=@PREFIX@/lib/X11/app-defaults
export CLASSPATH ; CLASSPATH=@PREFIX@/share/netscape/java/java_301
exec @EXECDIR@/netscape3.bin "$@"
