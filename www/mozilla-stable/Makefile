# $NetBSD: Makefile,v 1.12 2003/12/20 10:33:31 grant Exp $

PKGREVISION=	1
MOZILLA=	mozilla-stable
MOZILLA_BIN=	mozilla-bin
DISTNAME=	mozilla-${MOZ_DIST_VER}
MOZ_VER=	1.4.1
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	mozilla-source-1.4.1-libart_lgpl.tar.bz2

SITES_mozilla-source-1.4.1-libart_lgpl.tar.bz2=	${MASTER_SITE_LOCAL}

COMMENT=	Full featured gecko-based browser (stable branch)

USE_GCC_SHLIB=	yes
BUILD_SVG=	# defined
BUILD_CALENDAR=	# defined

.include	"../../www/mozilla/Makefile.common"
