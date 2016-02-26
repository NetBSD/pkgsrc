# $NetBSD: Makefile,v 1.3 2016/02/26 11:27:19 jperkin Exp $

DISTNAME=	xf86-video-modesetting-0.9.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Generic modesetting driver
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

USE_OLD_MODULAR_XORG_SERVER=		yes

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0.99.1
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
