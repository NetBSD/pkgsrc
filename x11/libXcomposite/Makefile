# $NetBSD: Makefile,v 1.15 2022/04/10 08:53:15 nia Exp $

DISTNAME=		libXcomposite-0.4.5
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Composite Library
LICENSE=		mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

X11_LIB_NAME?=		libXcomposite
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
