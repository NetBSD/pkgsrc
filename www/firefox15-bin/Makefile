# $NetBSD: Makefile,v 1.4 2008/03/07 05:14:04 jlam Exp $

MOZILLA=		firefox
MOZ_VER=		1.5.0.12
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.com/firefox/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-i386 solaris-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/seamonkey-bin/Makefile.common"
