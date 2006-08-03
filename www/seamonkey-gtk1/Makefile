# $NetBSD: Makefile,v 1.6 2006/08/03 09:37:35 ghen Exp $

MOZILLA=		seamonkey-gtk1
MOZILLA_BIN=		seamonkey-bin
MOZ_VER=		1.0.4
EXTRACT_SUFX=		.tar.bz2

DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTINFO_FILE=		${.CURDIR}/../../www/seamonkey/distinfo
PATCHDIR=		${.CURDIR}/../../www/seamonkey/patches
FILESDIR=		${.CURDIR}/../../www/mozilla/files

COMMENT=		Full featured gecko-based browser built with GTK1

BUILD_SVG=		# yes
BUILD_MATHML=		# yes
BUILD_CALENDAR=		# yes

.include "../../www/seamonkey/Makefile.common"
.include "../../mk/bsd.pkg.mk"
