# $NetBSD: Makefile,v 1.6 2009/03/19 00:30:39 mike Exp $

MOZILLA=		firefox
MOZ_VER=		3.0.2
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.com/en-US/firefox/
COMMENT=		Lightweight gecko-based web browser (binary package)

# requires newer version of GTK+ than supported by suse_gtk2 package
NOT_FOR_PLATFORM=	NetBSD-*-*

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}

EMUL_PLATFORMS=		linux-i386
#EMUL_PLATFORMS+=	solaris-i386 solaris-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/seamonkey-bin/Makefile.common"
