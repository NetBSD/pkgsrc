# $NetBSD: Makefile,v 1.5.2.1 2002/06/24 06:02:12 jlam Exp $
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
