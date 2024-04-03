# $NetBSD: Makefile,v 1.18 2024/04/03 21:26:00 wiz Exp $

DISTNAME=		libXmu-1.2.0
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Miscellaneous Utilities library

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xmu.pc.in
PKGCONFIG_OVERRIDE+=	xmuu.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

X11_LIB_NAME?=		libXmu
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXt+=	libXt>=1.1.0
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
