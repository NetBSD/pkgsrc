# $NetBSD: Makefile,v 1.5 2001/11/26 14:47:06 pooka Exp $
#

DISTNAME=	xworld-2.0
CATEGORIES=	x11
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/xworld/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	wennmach@geo.Uni-Koeln.DE
COMMENT=	Earth as seen from the direction of the sun

HAS_CONFIGURE=	yes

CONFIGURE_ENV+=	PREFIX="${PREFIX}"
CONFIGURE_ENV+=	LDLIBS="-lm ${LDFLAGS} -lX11"

.include "../../mk/bsd.pkg.mk"
