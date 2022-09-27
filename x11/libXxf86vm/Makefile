# $NetBSD: Makefile,v 1.16 2022/09/27 07:23:47 wiz Exp $

DISTNAME=		libXxf86vm-1.1.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Library for the XFree86-VidMode X extension

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xxf86vm.pc.in
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

.include "../../meta-pkgs/modular-xorg/hacks.mk"

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
