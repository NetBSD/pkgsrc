# $NetBSD: Makefile,v 1.27 2014/04/30 14:19:42 wiz Exp $

PKGNAME=	w3m-img-${W3M_VERS}
PKGREVISION=	5
COMMENT=	Multilingualized version of w3m with inline image support

CONFLICTS+=	w3m-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../www/w3m/distinfo
PATCHDIR=	${.CURDIR}/../../www/w3m/patches
PLIST_SRC=	${.CURDIR}/../../www/w3m/PLIST

USE_TOOLS+=	msgfmt

# Enable image support.
_W3M_USE_IMAGE=	YES

.include "../../www/w3m/Makefile.common"
