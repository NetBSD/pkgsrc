# $NetBSD: Makefile,v 1.1.1.1 2007/02/25 05:54:47 dsainty Exp $
#

DISTNAME=	xclock-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Analog / digital clock for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
