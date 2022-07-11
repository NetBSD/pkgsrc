# $NetBSD: Makefile,v 1.32 2022/07/11 19:48:15 wiz Exp $

DISTNAME=	xf86-input-keyboard-2.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg keyboard driver
LICENSE=	mit

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

RELRO_SUPPORTED=	partial

NOT_FOR_PLATFORM=	Linux-*

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	keyboard
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
