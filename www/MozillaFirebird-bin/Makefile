# $NetBSD: Makefile,v 1.7 2004/01/31 16:47:26 grant Exp $

MOZILLA=	MozillaFirebird

HOMEPAGE=	http://www.mozilla.org/projects/firebird/
COMMENT=	Lightweight gecko-based web browser (binary pkg)

# this package was formerly named "phoenix-linux", and "phoenix-bin".
CONFLICTS+=	phoenix-linux-[0-9]*
CONFLICTS+=	phoenix-bin-[0-9]*

ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86 NetBSD-*-i386
ONLY_FOR_PLATFORM+=	SunOS-5.[789]*-sparc SunOS-5.[89]*-i386

.include "../../www/mozilla-bin/Makefile.common"
