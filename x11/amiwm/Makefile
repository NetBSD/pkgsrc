# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:32 tsarna Exp $
#

DISTNAME=	amiwm0.20pl48
PKGNAME=	amiwm-0.20pl48
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	rh@trapdoor.vip.at
HOMEPAGE=	http://www.lysator.liu.se/~marcus/amiwm.html

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-DHAVE_X11_EXTENSIONS_SHAPE_H=1 -O"

.include "../../mk/bsd.pkg.mk"
