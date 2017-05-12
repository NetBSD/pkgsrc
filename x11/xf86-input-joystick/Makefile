# $NetBSD: Makefile,v 1.5 2017/05/12 03:18:03 maya Exp $

DISTNAME=	xf86-input-joystick-1.6.3
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

SUBST_CLASSES.DragonFly+=	usbhid
SUBST_STAGE.usbhid=		post-patch
SUBST_FILES.usbhid=		configure
SUBST_FILES.usbhid+=		src/backend_bsd.c
SUBST_SED.usbhid=		-e 's,dev/usb/,bus/u4b/,g'
SUBST_MESSAGE.usbhid=		Correct usbhid include paths

.include "../../x11/kbproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
