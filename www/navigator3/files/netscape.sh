#!/bin/sh
export XKEYSYMDB ; XKEYSYMDB=@X11BASE@/lib/X11/XKeysymDB
export XNLSPATH  ; XNLSPATH=@X11BASE@/share/netscape/nls
export XAPPLRESDIR ; XAPPLRESDIR=@X11BASE@/lib/X11/app-defaults
export CLASSPATH ; CLASSPATH=@X11BASE@/share/netscape/java/java_301
exec @EXECDIR@/netscape.bin "$@"
