# $NetBSD: Makefile,v 1.27 2007/03/21 13:33:05 ghen Exp $

MOZILLA=	firefox
MOZ_VER=	1.5.0.11
MOZ_DISTVER=	${MOZ_VER}

HOMEPAGE=	http://www.mozilla.com/firefox/
COMMENT=	Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=	${MOZILLA}/releases/${MOZ_DIR}
# binary package is built against GTK2
MOZ_GTK2=	YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/seamonkey-bin/Makefile.common"
