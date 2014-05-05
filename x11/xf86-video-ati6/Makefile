# $NetBSD: Makefile,v 1.5 2014/05/05 00:48:34 ryoon Exp $

DISTNAME=	xf86-video-ati-6.14.6
PKGNAME=	${DISTNAME:S/ati/ati6/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Radeon video driver (v6)

CONFIGURE_ARGS+=	--enable-dri

CONFLICTS+=	xf86-video-ati-[0-9]*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
