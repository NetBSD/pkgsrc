# $NetBSD: Makefile,v 1.15 2004/11/13 22:04:54 jlam Exp $

PKGREVISION=	2
MOZILLA=	mozilla-gtk2
MOZILLA_BIN=	mozilla-bin
MOZ_VER=	1.7.3
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTINFO_FILE=	${.CURDIR}/../../www/mozilla/distinfo
PATCHDIR=	${.CURDIR}/../../www/mozilla/patches
FILESDIR=	${.CURDIR}/../../www/mozilla/files

DISTFILES+=	mozilla-source-1.7.3-libart_lgpl.tar.bz2
SITES_mozilla-source-1.7.3-libart_lgpl.tar.bz2=${MASTER_SITE_LOCAL}

COMMENT=	Full featured gecko-based browser built with GTK2

BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

.include	"../../www/mozilla/Makefile.common"
