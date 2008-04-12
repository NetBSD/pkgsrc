# $NetBSD: Makefile,v 1.6 2008/04/12 22:43:15 jlam Exp $
#

DISTNAME=	xf86-video-via-0.2.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
COMMENT=	Modular Xorg VIA unichrome video driver

PKG_DESTDIR_SUPPORT=    user-destdir

CONFIGURE_ARGS+=	--enable-dri

USE_LIBTOOL=    yes
GNU_CONFIGURE=  yes
USE_TOOLS+=     pkg-config

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		XvMC
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.XvMC=		yes
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
