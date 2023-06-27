# $NetBSD: Makefile,v 1.31 2023/06/27 10:28:34 riastradh Exp $

DISTNAME=		libXext-1.3.5
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Extension library

TOOL_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xext.pc.in

CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${TOOLBASE}/bin/tradcpp -Uunix"
CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../meta-pkgs/modular-xorg/hacks.mk"

X11_LIB_NAME?=		libXext
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
