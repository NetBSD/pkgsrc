# $NetBSD: Makefile,v 1.1.1.1 2006/03/30 19:16:24 ghen Exp $

MOZILLA=		seamonkey-gtk1
MOZILLA_BIN=		seamonkey-bin
MOZ_VER=		1.0
EXTRACT_SUFX=		.tar.bz2

DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTINFO_FILE=		${.CURDIR}/../../wip/seamonkey/distinfo
PATCHDIR=		${.CURDIR}/../../wip/seamonkey/patches
FILESDIR=		${.CURDIR}/../../www/mozilla/files

COMMENT=		Full featured gecko-based browser built with GTK1

BUILD_SVG=		# yes
BUILD_MATHML=		# yes
BUILD_CALENDAR=		# yes

.include "../../wip/seamonkey/Makefile.common"
.include "../../mk/bsd.pkg.mk"
