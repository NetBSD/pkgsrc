# $NetBSD: Makefile,v 1.3 2006/04/15 08:36:04 ghen Exp $

MOZILLA=		seamonkey
MOZILLA_BIN=		seamonkey-bin
MOZ_VER=		1.0.1
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
