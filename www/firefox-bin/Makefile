# $NetBSD: Makefile,v 1.48 2008/12/17 17:05:52 ghen Exp $

MOZILLA=		firefox
MOZ_VER=		2.0.0.19
MOZ_DISTVER=		${MOZ_VER}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.mozilla.com/en-US/firefox/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-i386 solaris-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/seamonkey-bin/Makefile.common"
