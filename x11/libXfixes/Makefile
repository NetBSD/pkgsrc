# $NetBSD: Makefile,v 1.16 2022/04/10 08:53:15 nia Exp $

DISTNAME=		libXfixes-5.0.3
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org
LICENSE=		mit

CONFLICTS+=		Xfixes-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

X11_LIB_NAME?=		libXfixes
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
