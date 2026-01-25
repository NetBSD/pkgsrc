# $NetBSD: Makefile,v 1.38 2026/01/25 08:02:06 wiz Exp $

PKGNAME=	${DISTNAME:S/w3m-v/w3m-img-/}
COMMENT=	Multilingualized version of w3m with inline image support

CONFLICTS+=	w3m-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../www/w3m/distinfo
PATCHDIR=	${.CURDIR}/../../www/w3m/patches
PLIST_SRC=	${.CURDIR}/../../www/w3m/PLIST ${.CURDIR}/PLIST

USE_TOOLS+=	msgfmt

# Enable image support.
_W3M_USE_IMAGE=	YES

.include "../../www/w3m/Makefile.common"
.include "../../mk/bsd.pkg.mk"
