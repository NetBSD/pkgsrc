# $NetBSD: Makefile,v 1.29.2.1 2007/08/02 22:42:52 salo Exp $

MOZILLA=		firefox
MOZ_VER=		2.0.0.6
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.com/en-US/firefox/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}
# binary package is built against GTK2
MOZ_GTK2=		YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/seamonkey-bin/Makefile.common"
