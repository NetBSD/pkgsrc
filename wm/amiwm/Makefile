# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:29 wiz Exp $
#

DISTNAME=	amiwm0.20pl48
PKGNAME=	amiwm-0.20p48
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	rh@trapdoor.vip.at
HOMEPAGE=	http://www.lysator.liu.se/~marcus/amiwm.html
COMMENT=	X window manager with Amiga look and feel

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-DHAVE_X11_EXTENSIONS_SHAPE_H=1 -O" \
		X_PRE_LIBS="-Wl,-R${X11BASE}/lib" \
		X_EXTRA_LIBS="-lXt"

.include "../../mk/bsd.pkg.mk"
