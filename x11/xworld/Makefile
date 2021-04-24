# $NetBSD: Makefile,v 1.24 2021/04/24 00:17:23 wiz Exp $

DISTNAME=		xworld-2.0
PKGREVISION=		3
CATEGORIES=		x11
#MASTER_SITES=		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=		wennmach@NetBSD.org
COMMENT=		Earth as seen from the direction of the sun

HAS_CONFIGURE=		yes
USE_TOOLS+=		csh
CONFIG_SHELL=		${CSH}

CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_ENV+=		LDLIBS=-lm\ ${LDFLAGS:Q}\ -lX11
CONFIGURE_ENV+=		CAT=${CAT:Q} STRIP=strip INCLUDES="" MORELIBS=""

SUBST_CLASSES+=		x11
SUBST_MESSAGE.x11=	Fixing x11 options.
SUBST_STAGE.x11=	pre-configure
SUBST_FILES.x11=	defaults/NetBSD/set.csh
SUBST_FILES.x11+=	defaults/Solaris/set.csh
SUBST_VARS.x11=		X11BASE

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
