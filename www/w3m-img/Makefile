# $NetBSD: Makefile,v 1.4 2003/07/22 04:14:38 martti Exp $
#

PKGNAME=	w3m-img-${W3M_BASE_VERS}
PKGREVISION=	2
COMMENT=	Multilingualized version of a pager/text-based browser w3m with inline image support

CONFLICTS+=	w3m-[0-9]*

# enable image support
W3M_USE_IMAGE=	YES

PLIST_SRC=	${.CURDIR}/../../www/w3m/PLIST

.include "../../www/w3m/Makefile.common"
