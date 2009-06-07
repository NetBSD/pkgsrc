# $NetBSD: Makefile,v 1.19 2009/06/07 11:24:36 wiz Exp $

DISTNAME=	xf86-video-intel-2.7.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

CONFLICTS+=	xf86-video-i810-[0-9]*

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-dri

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
