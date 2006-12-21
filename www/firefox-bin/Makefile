# $NetBSD: Makefile,v 1.22.2.2 2006/12/21 04:19:37 salo Exp $

MOZILLA=	firefox
MOZ_VER=	1.5.0.9
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/${MOZ_DISTDIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/seamonkey-bin/Makefile.common"
