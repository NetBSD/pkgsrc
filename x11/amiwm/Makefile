# $NetBSD: Makefile,v 1.9 1999/07/07 21:11:06 tron Exp $
#

DISTNAME=	amiwm0.20pl48
PKGNAME=	amiwm-0.20p48
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	rh@trapdoor.vip.at
HOMEPAGE=	http://www.lysator.liu.se/~marcus/amiwm.html

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-DHAVE_X11_EXTENSIONS_SHAPE_H=1 -O" \
		X_PRE_LIBS="-Wl,-R${X11BASE}" \
		X_EXTRA_LIBS="-lXt"

.include "../../mk/bsd.pkg.mk"
