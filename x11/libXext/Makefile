# $NetBSD: Makefile,v 1.23 2016/02/26 11:27:14 jperkin Exp $

DISTNAME=		libXext-1.3.3
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
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

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.1.99
.include "../../x11/xextproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.xproto+=		xproto>=7.0.13
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
