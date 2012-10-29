# $NetBSD: Makefile,v 1.6 2012/10/29 05:06:57 asau Exp $
#

DISTNAME=	xbacklight-1.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Adjust backlight brightness using RandR extension

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
