# $NetBSD: Makefile,v 1.45.2.1 2008/11/14 12:32:59 tron Exp $

MOZILLA=		firefox
MOZ_VER=		2.0.0.18
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.com/en-US/firefox/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-i386 solaris-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/seamonkey-bin/Makefile.common"
