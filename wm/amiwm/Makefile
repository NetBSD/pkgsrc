# $NetBSD: Makefile,v 1.14 2005/12/05 20:51:09 rillig Exp $
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

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
CFLAGS+=	-DHAVE_X11_EXTENSIONS_SHAPE_H=1
CFLAGS+=	-O
CONFIGURE_ENV+=	CFLAGS=${CFLAGS:M*:Q}
CONFIGURE_ENV+=	X_PRE_LIBS=${X_PRE_LIBS:Q}
CONFIGURE_ENV+=	X_EXTRA_LIBS=-lXt

X_PRE_LIBS=	${COMPILER_RPATH_FLAG}${X11BASE}/lib
FIX_RPATH+=	X_PRE_LIBS

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
