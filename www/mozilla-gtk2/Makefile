# $NetBSD: Makefile,v 1.4 2004/03/06 13:45:37 jmmv Exp $

MOZILLA=	mozilla-gtk2
MOZILLA_BIN=	mozilla-bin
MOZ_VER=	1.6
PKGREVISION=	3
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
PATCHDIR=	../../www/mozilla/patches
FILESDIR=	../../www/mozilla/files

COMMENT=	Full featured gecko-based browser built on gtk2

USE_GCC_SHLIB=	yes
BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

.include	"../../www/mozilla/Makefile.common"
