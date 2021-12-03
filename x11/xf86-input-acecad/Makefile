# $NetBSD: Makefile,v 1.12 2021/12/03 12:50:13 nia Exp $

DISTNAME=	xf86-input-acecad-1.5.0
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Acecad Flair input driver for the Xorg X server
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_BUILTIN_NAME=	xf86-input-acecad
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
