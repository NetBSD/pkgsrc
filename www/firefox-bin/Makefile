# $NetBSD: Makefile,v 1.47 2008/11/20 13:11:18 tron Exp $

MOZILLA=		firefox
MOZ_VER=		2.0.0.18
MOZ_DISTVER=		${MOZ_VER}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.mozilla.com/en-US/firefox/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-i386 solaris-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/seamonkey-bin/Makefile.common"
