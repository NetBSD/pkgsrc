# $NetBSD: Makefile,v 1.5 2022/04/10 08:53:16 nia Exp $

DISTNAME=		libXpresent-1.0.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xlib-compatible API for the Present extension

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xpresent.pc.in
GNU_CONFIGURE=		yes

X11_LIB_NAME?=		libXpresent
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
