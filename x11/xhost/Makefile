# $NetBSD: Makefile,v 1.1.1.1 2007/02/25 04:29:15 dsainty Exp $
#

DISTNAME=	xhost-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Server access control program for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
