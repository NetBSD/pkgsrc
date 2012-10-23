# $NetBSD: Makefile,v 1.13 2012/10/23 10:24:22 wiz Exp $
#

DISTNAME=	xlupe-1.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://core.de/~coto/projects/xlupe/

MAINTAINER=	coto@core.de
HOMEPAGE=	http://core.de/~coto/projects/xlupe/
COMMENT=	Magnifier for X

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
