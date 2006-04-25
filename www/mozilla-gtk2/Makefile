# $NetBSD: Makefile,v 1.35.2.1 2006/04/25 11:01:27 salo Exp $

MOZILLA=		mozilla-gtk2
MOZILLA_BIN=		mozilla-bin
MOZ_VER=		1.7.13
EXTRACT_SUFX=		.tar.bz2

DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
#DISTFILES+=		mozilla-source-1.7.3-libart_lgpl.tar.bz2
#SITES_mozilla-source-1.7.3-libart_lgpl.tar.bz2=${MASTER_SITE_LOCAL}
DIST_SUBDIR=		mozilla-1.7.13
DISTINFO_FILE=		${.CURDIR}/../../www/mozilla/distinfo
PATCHDIR=		${.CURDIR}/../../www/mozilla/patches
FILESDIR=		${.CURDIR}/../../www/mozilla/files

COMMENT=		Full featured gecko-based browser built with GTK2

BUILD_SVG=		# yes
BUILD_MATHML=		# yes
BUILD_CALENDAR=		# yes

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

.include "../../www/mozilla/Makefile.common"
.include "../../mk/bsd.pkg.mk"
