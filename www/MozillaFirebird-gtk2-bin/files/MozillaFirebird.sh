#!@SH@
# $NetBSD: MozillaFirebird.sh,v 1.1.1.1 2003/12/30 22:48:32 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/MozillaFirebird-gtk2-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/MozillaFirebird-gtk2-@PLATFORM@/MozillaFirebird "$@"
