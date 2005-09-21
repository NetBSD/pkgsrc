# $NetBSD: Makefile,v 1.10 2005/09/21 10:07:39 tron Exp $

MOZILLA=	firefox
MOZ_VER=	1.0.7
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
