# $NetBSD: Makefile,v 1.35 2024/12/17 13:35:10 ryoon Exp $

PKGNAME=	w3m-img-${W3M_PKGVERS}
PKGREVISION=	3
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
