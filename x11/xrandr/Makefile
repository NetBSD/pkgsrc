# $NetBSD: Makefile,v 1.1.1.1 2007/02/26 17:55:48 drochner Exp $
#

DISTNAME=	xrandr-1.2.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Primitive command line interface to RandR extension

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
