# $NetBSD: Makefile,v 1.11 2005/06/01 18:03:33 jlam Exp $
#

DISTNAME=		xworld-2.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://gutemine.geo.uni-koeln.de/pub/xworld/ \
			ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=		wennmach@NetBSD.org
COMMENT=		Earth as seen from the direction of the sun

HAS_CONFIGURE=		yes

CONFIGURE_ENV+=		PREFIX="${PREFIX}"
CONFIGURE_ENV+=		LDLIBS="-lm ${LDFLAGS} -lX11"
CONFIGURE_ENV+=		CAT="${CAT}" STRIP=strip INCLUDES="" MORELIBS=""

SUBST_CLASSES+=		install
SUBST_MESSAGE.install=	"Fixing install options."
SUBST_STAGE.install=	post-patch
SUBST_FILES.install=	Makefile.in
SUBST_SED.install=	-e 's,-g bin -o bin,-g ${BINGRP} -o ${BINOWN},g'

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
