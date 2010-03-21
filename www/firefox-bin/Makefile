# $NetBSD: Makefile,v 1.50 2010/03/21 16:29:44 wiz Exp $

MOZILLA=		firefox
MOZ_VER=		2.0.0.20
MOZ_DISTVER=		${MOZ_VER}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mozilla.com/en-US/firefox/
COMMENT=		Lightweight gecko-based web browser (binary package)

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-i386 solaris-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/seamonkey-bin/Makefile.common"
