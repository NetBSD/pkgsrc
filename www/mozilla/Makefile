# $NetBSD: Makefile,v 1.156.2.1 2006/04/25 11:01:26 salo Exp $

MOZILLA=		mozilla
MOZILLA_BIN=		mozilla-bin
MOZ_VER=		1.7.13
EXTRACT_SUFX=		.tar.bz2

DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
#DISTFILES+=		mozilla-source-1.7.3-libart_lgpl.tar.bz2
#SITES_mozilla-source-1.7.3-libart_lgpl.tar.bz2=${MASTER_SITE_LOCAL}

DIST_SUBDIR=		mozilla-1.7.13

COMMENT=		Full featured gecko-based browser

BUILD_SVG=		# yes
BUILD_MATHML=		# yes
BUILD_CALENDAR=		# yes

.include "../../www/mozilla/Makefile.common"
.include "../../mk/bsd.pkg.mk"
