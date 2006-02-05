# $NetBSD: Makefile,v 1.14 2006/02/05 23:11:21 joerg Exp $

MOZILLA=	firefox
PKGREVISION=	1
MOZ_VER=	1.5.0.1
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
