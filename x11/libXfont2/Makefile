# $NetBSD: Makefile,v 1.13 2022/04/10 08:53:15 nia Exp $

DISTNAME=		libXfont2-2.0.5
CATEGORIES=		x11 devel fonts
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X font Library (v2)
LICENSE=		mit AND modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_FEATURES+=		strnlen

PKGCONFIG_OVERRIDE+=	xfont2.pc.in

CONFIGURE_ARGS+=	--disable-devel-docs
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

X11_LIB_NAME?=		libXfont2
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
