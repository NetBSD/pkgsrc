# $NetBSD: Makefile,v 1.21 2024/12/14 12:41:03 wiz Exp $

DISTNAME=		libSM-1.2.5
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Session Management Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	sm.pc.in

CONFIGURE_ARGS+=	--without-libuuid

.include "options.mk"

X11_LIB_NAME?=		libSM
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
BUILDLINK_API_DEPENDS.libICE+=	libICE>=1.1.0
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
