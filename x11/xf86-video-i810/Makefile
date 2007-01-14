# $NetBSD: Makefile,v 1.1.1.1 2007/01/14 10:13:54 joerg Exp $

DISTNAME=	xf86-video-i810-1.7.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
COMMENT=	Modular Xorg Intel video driver

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.if 0
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
