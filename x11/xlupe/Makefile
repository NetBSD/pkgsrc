# $NetBSD: Makefile,v 1.12 2012/05/03 09:55:32 obache Exp $
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
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
