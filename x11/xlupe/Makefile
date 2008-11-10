# $NetBSD: Makefile,v 1.11 2008/11/10 17:21:39 wiz Exp $
#

DISTNAME=	xlupe-1.1
PKGREVISION=	2
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
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
