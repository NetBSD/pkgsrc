# $NetBSD: Makefile,v 1.8 2003/03/14 19:37:59 jlam Exp $
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

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-DHAVE_X11_EXTENSIONS_SHAPE_H=1 -O" \
		X_PRE_LIBS="${X_PRE_LIBS}" \
		X_EXTRA_LIBS="-lXt"

X_PRE_LIBS=	-Wl,${RPATH_FLAG}${X11BASE}/lib
FIX_RPATH+=	X_PRE_LIBS

.include "../../mk/bsd.pkg.mk"
