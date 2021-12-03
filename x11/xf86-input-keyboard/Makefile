# $NetBSD: Makefile,v 1.30 2021/12/03 12:50:13 nia Exp $

DISTNAME=	xf86-input-keyboard-1.9.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg keyboard driver
LICENSE=	mit

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_BUILTIN_NAME=	xf86-input-keyboard
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
