# $NetBSD: Makefile,v 1.7 2009/06/08 23:19:12 ahoka Exp $

MOZILLA=		firefox
MOZ_VER=		3.0.2
MOZ_DISTVER=		${MOZ_VER}

HOMEPAGE=		http://www.mozilla.com/en-US/firefox/
COMMENT=		Web browser with support for extensions (binary package)

# requires newer version of GTK+ than supported by suse_gtk2 package
NOT_FOR_PLATFORM=	NetBSD-*-*

DIST_SUBDIR=		${MOZILLA}/releases/${MOZ_DIR}

EMUL_PLATFORMS=		linux-i386
#EMUL_PLATFORMS+=	solaris-i386 solaris-sparc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../www/seamonkey-bin/Makefile.common"
