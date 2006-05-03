# $NetBSD: Makefile,v 1.15.2.2 2006/05/03 09:11:08 salo Exp $

MOZILLA=	firefox
MOZ_VER=	1.5.0.3
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/mozilla-bin/Makefile.common"
