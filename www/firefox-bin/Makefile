# $NetBSD: Makefile,v 1.15 2006/03/10 22:45:24 wiz Exp $

MOZILLA=	firefox
PKGREVISION=	2
MOZ_VER=	1.5.0.1
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
