# $NetBSD: Makefile,v 1.6 2016/01/05 13:11:44 tnn Exp $

DISTNAME=	xf86-video-nouveau-1.0.12
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	New (or nouveau) NVidia driver for modular X.org

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
