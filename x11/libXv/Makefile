# $NetBSD: Makefile,v 1.18 2020/01/18 23:35:53 rillig Exp $

DISTNAME=		libXv-1.0.11
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xv Extension library

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xv.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../meta-pkgs/modular-xorg/hacks.mk"

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
