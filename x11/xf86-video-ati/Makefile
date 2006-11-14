# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 17:16:27 joerg Exp $

DISTNAME=	xf86-video-ati-6.6.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
COMMENT=	Modular Xorg ATI video driver

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../wip/modular-xorg-server/buildlink3.mk"

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../wip/libdrm/buildlink3.mk"
.include "../../wip/glproto/buildlink3.mk" # configure wrong
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../wip/xf86miscproto/buildlink3.mk"
.include "../../wip/xf86driproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
