# $NetBSD: Makefile,v 1.2 2015/07/04 06:41:53 richard Exp $

DISTNAME=	xf86-video-qxl-0.1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	QXL virtual GPU
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-D__EXTENSIONS__
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.46
.include "../../x11/libdrm/buildlink3.mk"
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
