# $NetBSD: Makefile,v 1.19 2023/06/27 10:29:40 riastradh Exp $

DISTNAME=		libXrender-0.9.11
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Render Library
LICENSE=		mit

CONFLICTS+=		Xrender-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

PKGCONFIG_OVERRIDE+=	xrender.pc.in

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/xorgproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
