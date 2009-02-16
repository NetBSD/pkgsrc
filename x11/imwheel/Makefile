# $NetBSD: Makefile,v 1.13 2009/02/16 18:21:24 joerg Exp $
#

DISTNAME=	imwheel-0.9.9
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imwheel/}

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://imwheel.sourceforge.net/
COMMENT=	Tool which helps to use mousewheels

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
