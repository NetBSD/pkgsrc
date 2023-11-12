# $NetBSD: Makefile,v 1.32 2023/11/12 13:24:33 wiz Exp $

DISTNAME=	xf86-input-vmmouse-13.2.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg VMware virtual mouse driver

USE_LANGUAGES=	c99
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

RELRO_SUPPORTED=	partial

# #error The vmmouse protocol is only supported on x86 architectures.
ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

# Currently libudev is unsupported in pkgsrc
CONFIGURE_ARGS+=	--without-libudev

X11_DRV_NAME=	vmmouse
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
