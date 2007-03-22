# $NetBSD: Makefile,v 1.1.1.1 2007/03/22 15:44:20 joerg Exp $
#

DISTNAME=	xf86-video-sis-0.9.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
COMMENT=	Modular Xorg SiS and XGI video driver

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes
USE_TOOLS+=     pkg-config

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
