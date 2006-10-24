# $NetBSD: Makefile,v 1.1.1.1 2006/10/24 22:20:58 ghen Exp $

MOZILLA=		firefox
MOZ_EXTRA=		2
MOZ_VER=		2.0
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.com/en-US/firefox/2.0/releasenotes/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=		YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

WRKSRC=			${WRKDIR}/firefox

.include "../../www/seamonkey-bin/Makefile.common"
