# $NetBSD: Makefile,v 1.4 2004/05/22 12:42:58 grant Exp $
#

MOZILLA=	firefox

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser (gtk2 nightly binary pkg)

MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	NetBSD-2.*-i386
ONLY_FOR_PLATFORM+=	SunOS-5.[89]*-sparc

.include "../../www/mozilla-bin-nightly/Makefile.common"
