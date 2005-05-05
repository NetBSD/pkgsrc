# $NetBSD: Makefile,v 1.9 2005/05/05 20:50:49 kei Exp $
#

PKGNAME=	w3m-img-${W3M_VERS}
PKGREVISION=	3
COMMENT=	Multilingualized version of a pager/text-based browser w3m with inline image support

CONFLICTS+=	w3m-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../www/w3m/distinfo
PATCHDIR=	${.CURDIR}/../../www/w3m/patches
PLIST_SRC=	${.CURDIR}/../../www/w3m/PLIST

# Enable image support.
_W3M_USE_IMAGE=	YES

.include "../../www/w3m/Makefile.common"
