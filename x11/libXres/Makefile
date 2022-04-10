# $NetBSD: Makefile,v 1.17 2022/04/10 08:53:16 nia Exp $

DISTNAME=		libXres-1.2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Resource Information Extension Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xres.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

X11_LIB_NAME?=		libXres
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
