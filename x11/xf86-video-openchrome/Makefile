# $NetBSD: Makefile,v 1.18 2016/02/26 11:27:19 jperkin Exp $

DISTNAME=	xf86-video-openchrome-0.3.3
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://www.openchrome.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openchrome.org/
COMMENT=	Modular Xorg OpenChrome driver for VIA UniChrome video chipsets

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-maintainer-mode
CONFIGURE_ARGS+=	--enable-dri

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		XvMC
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.XvMC=		yes
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
