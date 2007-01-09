# $NetBSD: Makefile,v 1.14 2007/01/09 08:07:44 joerg Exp $
#

PKGREVISION=	6
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Desktop File Manager

post-install:
	${MV} ${PREFIX}/${PKGMANDIR}/man1/dfm.1x ${PREFIX}/${PKGMANDIR}/man1/dfm.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "Makefile.common"
