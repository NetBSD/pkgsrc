# $NetBSD: Makefile,v 1.27 2023/10/05 22:12:06 wiz Exp $

DISTNAME=		libXrandr-1.5.4
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X RandR Library from X.org

CONFLICTS+=		Xrandr-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xrandr.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

X11_LIB_NAME?=		libXrandr
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
