# $NetBSD: Makefile,v 1.7 2004/06/01 15:02:55 taya Exp $

MOZILLA=	mozilla-gtk2
MOZILLA_BIN=	mozilla-bin
MOZCONFDIR=     .mozilla
MOZ_VER=	1.6
PKGREVISION=	4
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTINFO_FILE=	${.CURDIR}/../../www/mozilla/distinfo
PATCHDIR=	${.CURDIR}/../../www/mozilla/patches
FILESDIR=	${.CURDIR}/../../www/mozilla/files

COMMENT=	Full featured gecko-based browser built with GTK2

USE_GCC_SHLIB=	yes
BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

.include	"../../www/mozilla/Makefile.common"
