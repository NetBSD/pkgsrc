# $NetBSD: Makefile,v 1.8 2004/01/04 05:01:03 grant Exp $

MOZILLA=	MozillaFirebird
HOMEPAGE=	http://www.mozilla.org/projects/firebird/

# this package was formerly named "phoenix-linux", and "phoenix-bin".
CONFLICTS+=	phoenix-linux-[0-9]*
CONFLICTS+=	phoenix-bin-[0-9]*

# see Makefile.NetBSD.i386.
ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86
ONLY_FOR_PLATFORM+=	SunOS-5.[789]*-sparc

.include "../../www/mozilla-bin-nightly/Makefile.common"
