# $NetBSD: Makefile,v 1.14 2023/01/29 21:18:25 ryoon Exp $

DISTNAME=	xf86-input-penmount-1.5.0
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	PenMount input driver for the Xorg X server
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

RELRO_SUPPORTED=	partial

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

X11_DRV_NAME=	penmount
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
