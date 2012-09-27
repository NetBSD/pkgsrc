# $NetBSD: Makefile,v 1.7 2012/09/27 10:06:31 jperkin Exp $
#

DISTNAME=	xf86-video-openchrome-0.2.904
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.openchrome.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openchrome.org/
COMMENT=	Modular Xorg OpenChrome driver for VIA UniChrome video chipsets

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-maintainer-mode
CONFIGURE_ARGS+=	--enable-dri

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		XvMC
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.XvMC=		yes
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
