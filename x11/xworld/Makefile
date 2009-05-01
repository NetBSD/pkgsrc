# $NetBSD: Makefile,v 1.19 2009/05/01 15:33:43 zafer Exp $
#

DISTNAME=		xworld-2.0
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=		wennmach@NetBSD.org
COMMENT=		Earth as seen from the direction of the sun

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_TOOLS+=		csh
CONFIG_SHELL=		${CSH}

CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
CONFIGURE_ENV+=		LDLIBS="-lm ${LDFLAGS} -lX11"
CONFIGURE_ENV+=		CAT=${CAT:Q} STRIP=strip INCLUDES="" MORELIBS=""

SUBST_CLASSES+=		x11
SUBST_MESSAGE.x11=	Fixing x11 options.
SUBST_STAGE.x11=	post-patch
SUBST_FILES.x11=	defaults/NetBSD/set.csh
SUBST_SED.x11=		-e 's,@X11BASE@,${X11BASE},g'

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
