# $NetBSD: Makefile,v 1.28 2022/04/10 08:53:15 nia Exp $

DISTNAME=		libXext-1.3.4
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Extension library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xext.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../mk/compiler.mk"

TOOL_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${PREFIX}/bin/tradcpp -Uunix"

.include "../../meta-pkgs/modular-xorg/hacks.mk"

X11_LIB_NAME?=		libXext
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
