# $NetBSD: Makefile,v 1.6 2002/03/12 22:25:18 jmc Exp $
#

DISTNAME=	amiwm0.20pl48
PKGNAME=	amiwm-0.20p48
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	rh@trapdoor.vip.at
HOMEPAGE=	http://www.lysator.liu.se/~marcus/amiwm.html
COMMENT=	X window manager with Amiga look and feel

LICENSE=	amiwm-license
RESTRICTED=     "Restrictive copyright (non-commerical use only)"
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

USE_BUILDLINK_ONLY=	YES
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-DHAVE_X11_EXTENSIONS_SHAPE_H=1 -O" \
		X_PRE_LIBS="-Wl,-R${X11BASE}/lib" \
		X_EXTRA_LIBS="-lXt"

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
