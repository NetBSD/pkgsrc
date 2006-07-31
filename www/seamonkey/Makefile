# $NetBSD: Makefile,v 1.6 2006/07/31 11:58:04 ghen Exp $

MOZILLA=		seamonkey
MOZILLA_BIN=		seamonkey-bin
MOZ_VER=		1.0.3
EXTRACT_SUFX=		.tar.bz2

DISTFILES=		${DISTNAME}${EXTRACT_SUFX}

COMMENT=		Full featured gecko-based browser

BUILD_SVG=		# yes
BUILD_MATHML=		# yes
BUILD_CALENDAR=		# yes

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

.include "../../www/seamonkey/Makefile.common"
.include "../../mk/bsd.pkg.mk"
