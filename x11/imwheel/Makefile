# $NetBSD: Makefile,v 1.16 2012/10/29 05:06:21 asau Exp $
#

DISTNAME=	imwheel-0.9.9
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imwheel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://imwheel.sourceforge.net/
COMMENT=	Tool which helps to use mousewheels

USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
