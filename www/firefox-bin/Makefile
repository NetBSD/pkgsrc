# $NetBSD: Makefile,v 1.7 2005/05/12 15:06:58 tron Exp $

MOZILLA=	firefox
MOZ_VER=	1.0.4
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
