# $NetBSD: Makefile,v 1.5 2004/03/11 08:27:09 grant Exp $

MOZILLA=	mozilla-gtk2
MOZILLA_BIN=	mozilla-bin
MOZ_VER=	1.6
PKGREVISION=	3
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PATCHDIR=	../../www/mozilla/patches
FILESDIR=	../../www/mozilla/files

COMMENT=	Full featured gecko-based browser built with GTK2

USE_GCC_SHLIB=	yes
BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

.include	"../../www/mozilla/Makefile.common"
