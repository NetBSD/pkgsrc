# $NetBSD: Makefile,v 1.138 2004/10/25 18:06:25 jmmv Exp $

PKGREVISION=	1
MOZILLA=	mozilla
MOZILLA_BIN=	mozilla-bin
MOZ_VER=	1.7.3
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	mozilla-source-1.7.3-libart_lgpl.tar.bz2
SITES_mozilla-source-1.7.3-libart_lgpl.tar.bz2=${MASTER_SITE_LOCAL}

COMMENT=	Full featured gecko-based browser

USE_GCC_SHLIB=	yes
BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

.include	"../../www/mozilla/Makefile.common"
