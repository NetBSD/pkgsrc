# $NetBSD: Makefile,v 1.18 2005/04/01 08:59:12 abs Exp $

MOZILLA=	mozilla-gtk2
MOZILLA_BIN=	mozilla-bin
MOZ_VER=	1.7.6
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTINFO_FILE=	${.CURDIR}/../../www/mozilla/distinfo
PATCHDIR=	${.CURDIR}/../../www/mozilla/patches
FILESDIR=	${.CURDIR}/../../www/mozilla/files

COMMENT=	Full featured gecko-based browser built with GTK2

BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES
CONFIGURE_ARGS+=	--disable-gnomevfs

.include	"../../www/mozilla/Makefile.common"
