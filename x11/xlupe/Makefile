# $NetBSD: Makefile,v 1.10 2008/07/14 12:56:20 joerg Exp $
#

DISTNAME=	xlupe-1.1
PKGREVISION=	1
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
