# $NetBSD: Makefile,v 1.29 2005/09/17 02:35:20 jlam Exp $

MOZILLA=	mozilla-gtk2
MOZILLA_BIN=	mozilla-bin
MOZ_VER=	1.7.11
EXTRACT_SUFX=	.tar.bz2
PKGREVISION=	2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
#DISTFILES+=	mozilla-source-1.7.3-libart_lgpl.tar.bz2
#SITES_mozilla-source-1.7.3-libart_lgpl.tar.bz2=${MASTER_SITE_LOCAL}
DIST_SUBDIR=	mozilla-1.7.11
DISTINFO_FILE=	${.CURDIR}/../../www/mozilla/distinfo
PATCHDIR=	${.CURDIR}/../../www/mozilla/patches
FILESDIR=	${.CURDIR}/../../www/mozilla/files

COMMENT=	Full featured gecko-based browser built with GTK2

BUILD_SVG=	# defined
BUILD_MATHML=	# defined
BUILD_CALENDAR=	# defined

_MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

.include "../../www/mozilla/Makefile.common"
.include "../../mk/bsd.pkg.mk"
