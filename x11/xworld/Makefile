# $NetBSD: Makefile,v 1.13 2005/12/05 20:51:20 rillig Exp $
#

DISTNAME=		xworld-2.0
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		ftp://gutemine.geo.uni-koeln.de/pub/xworld/ \
			ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=		wennmach@NetBSD.org
COMMENT=		Earth as seen from the direction of the sun

HAS_CONFIGURE=		yes

CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
CONFIGURE_ENV+=		LDLIBS="-lm ${LDFLAGS} -lX11"
CONFIGURE_ENV+=		CAT=${CAT:Q} STRIP=strip INCLUDES="" MORELIBS=""

SUBST_CLASSES+=		x11
SUBST_MESSAGE.x11=	"Fixing x11 options."
SUBST_STAGE.x11=	post-patch
SUBST_FILES.x11=	defaults/NetBSD/set.csh
SUBST_SED.x11=		-e 's,@X11BASE@,${X11BASE},g'

SUBST_CLASSES+=		install
SUBST_MESSAGE.install=	"Fixing install options."
SUBST_STAGE.install=	post-patch
SUBST_FILES.install=	Makefile.in
SUBST_SED.install=	-e 's,-g bin -o bin,-g ${BINGRP} -o ${BINOWN},g'

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
