#!@SH@
# $NetBSD: MozillaFirebird.sh,v 1.1 2003/09/27 14:13:08 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/MozillaFirebird-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/MozillaFirebird-@PLATFORM@/MozillaFirebird "$@"
