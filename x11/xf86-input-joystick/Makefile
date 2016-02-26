# $NetBSD: Makefile,v 1.3 2016/02/26 11:27:17 jperkin Exp $

DISTNAME=	xf86-input-joystick-1.6.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Joystick input driver for the Xorg X server
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xorg-joystick.pc.in

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../x11/kbproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
