#!@SH@
# $NetBSD: phoenix.sh,v 1.3 2003/05/25 06:52:53 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/MozillaFirebird-@PLATFORM@"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/MozillaFirebird-@PLATFORM@/MozillaFirebird "$@"
