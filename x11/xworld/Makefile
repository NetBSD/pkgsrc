# $NetBSD: Makefile,v 1.6 2002/08/25 21:53:04 jlam Exp $
#

DISTNAME=	xworld-2.0
CATEGORIES=	x11
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/xworld/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	wennmach@geo.Uni-Koeln.DE
COMMENT=	Earth as seen from the direction of the sun

USE_BUILDLINK2=	yes
HAS_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ENV+=	PREFIX="${PREFIX}"
CONFIGURE_ENV+=	LDLIBS="-lm ${LDFLAGS} -lX11"

.include "../../mk/bsd.pkg.mk"
