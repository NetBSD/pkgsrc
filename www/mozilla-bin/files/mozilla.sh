#!@SH@
# $NetBSD: mozilla.sh,v 1.3 2003/07/18 07:31:16 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/mozilla-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/mozilla-@PLATFORM@/mozilla "$@"
