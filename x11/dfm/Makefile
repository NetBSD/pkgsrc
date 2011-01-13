# $NetBSD: Makefile,v 1.19 2011/01/13 13:39:42 wiz Exp $
#

PKGREVISION=	10
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Desktop File Manager

PKG_DESTDIR_SUPPORT=	user-destdir

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dfm.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dfm.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "Makefile.common"
