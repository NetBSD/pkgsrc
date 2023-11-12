# $NetBSD: Makefile,v 1.37 2023/11/12 13:24:38 wiz Exp $

DISTNAME=	xf86-video-vmware-13.4.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg VMware virtual video driver
LICENSE=	mit

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64 *-*-*arm* *-*-aarch64

.include "options.mk"

X11_DRV_NAME=	vmware
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXext?=	build
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
