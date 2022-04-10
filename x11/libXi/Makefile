# $NetBSD: Makefile,v 1.39 2022/04/10 08:53:16 nia Exp $

DISTNAME=		libXi-1.8
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Input extension library
LICENSE=		mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3 ac_cv_path_ASCIIDOC= ac_cv_path_XMLTO=
PKGCONFIG_OVERRIDE+=	xi.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

X11_LIB_NAME?=		libXi
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.6
BUILDLINK_API_DEPENDS.libXext+=		libXext>=1.1
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
BUILDLINK_API_DEPENDS.xorgproto+=	xorgproto>=2021.5nb1
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
