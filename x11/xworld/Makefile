# $NetBSD: Makefile,v 1.7 2004/02/05 22:19:45 wennmach Exp $
#

DISTNAME=		xworld-2.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://gutemine.geo.uni-koeln.de/pub/xworld/ \
			ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=		wennmach@NetBSD.org
COMMENT=		Earth as seen from the direction of the sun

USE_BUILDLINK2=		yes
HAS_CONFIGURE=		yes
USE_X11=		yes

CONFIGURE_ENV+=		PREFIX="${PREFIX}"
CONFIGURE_ENV+=		LDLIBS="-lm ${LDFLAGS} -lX11"

SUBST_CLASSES+=		install
SUBST_MESSAGE.install=	"Fixing install options."
SUBST_STAGE.install=	post-patch
SUBST_FILES.install=	Makefile.in
SUBST_SED.install=	-e 's,-g bin -o bin,-g ${BINGRP} -o ${BINOWN},g'

.include "../../mk/bsd.pkg.mk"
