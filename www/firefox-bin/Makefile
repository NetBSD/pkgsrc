# $NetBSD: Makefile,v 1.23 2006/11/08 09:50:15 ghen Exp $

MOZILLA=	firefox
MOZ_VER=	1.5.0.8
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/seamonkey-bin/Makefile.common"
