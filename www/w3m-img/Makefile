# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 19:04:48 jlam Exp $
#

PKGNAME=	w3m-img-${W3M_BASE_VERS}
COMMENT=	multilingualized version of a pager/text-based browser w3m with inline image support

CONFLICTS+=	w3m-[0-9]*

# enable image support
W3M_USE_IMAGE=	YES

PLIST_SRC=	${.CURDIR}/../../www/w3m/PLIST

.include "../../www/w3m/Makefile.common"
