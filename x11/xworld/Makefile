# $NetBSD: Makefile,v 1.2 2000/08/17 15:26:31 fredb Exp $
#

DISTNAME=	xworld-2.0
CATEGORIES=	x11
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/xworld/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	wennmach@geo.Uni-Koeln.DE
#HOMEPAGE=

HAS_CONFIGURE=	yes

CONFIGURE_ENV+=	LDLIBS="-lm ${LDFLAGS} -lX11"

.include "../../mk/bsd.pkg.mk"
