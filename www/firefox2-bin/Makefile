# $NetBSD: Makefile,v 1.6.2.1 2007/06/13 21:32:55 salo Exp $

MOZILLA=		firefox
MOZ_VER=		2.0.0.4
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.com/en-US/firefox/2.0/releasenotes/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}
# binary package is built against GTK2
MOZ_GTK2=		YES

ONLY_FOR_PLATFORM+=	Linux-*-i386

.include "../../www/seamonkey-bin/Makefile.common"
