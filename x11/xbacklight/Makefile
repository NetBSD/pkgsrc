# $NetBSD: Makefile,v 1.5 2012/09/12 06:35:56 wiz Exp $
#

DISTNAME=	xbacklight-1.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Adjust backlight brightness using RandR extension

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
