# $NetBSD: Makefile,v 1.152 2005/10/01 04:42:09 taya Exp $

MOZILLA=	mozilla
MOZILLA_BIN=	mozilla-bin
MOZ_VER=	1.7.12
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
#DISTFILES+=    mozilla-source-1.7.3-libart_lgpl.tar.bz2
#SITES_mozilla-source-1.7.3-libart_lgpl.tar.bz2=${MASTER_SITE_LOCAL}

DIST_SUBDIR=	mozilla-1.7.12

COMMENT=	Full featured gecko-based browser

BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

.include "../../www/mozilla/Makefile.common"
.include "../../mk/bsd.pkg.mk"
