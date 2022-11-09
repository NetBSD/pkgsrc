# $NetBSD: Makefile,v 1.21 2022/11/09 13:14:21 joerg Exp $

DISTNAME=	libXinerama-1.1.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	X PanoramiX extension library

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xinerama.pc.in

X11_LIB_NAME?=		libXinerama
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
