# $NetBSD: Makefile,v 1.4 2001/05/17 08:32:14 abs Exp $
#

DISTNAME=	xworld-2.0
CATEGORIES=	x11
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/xworld/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	wennmach@geo.Uni-Koeln.DE
COMMENT=	Earth as seen from the direction of the sun

HAS_CONFIGURE=	yes

CONFIGURE_ENV+=	LDLIBS="-lm ${LDFLAGS} -lX11"

.include "../../mk/bsd.pkg.mk"
