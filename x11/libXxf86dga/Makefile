# $NetBSD: Makefile,v 1.20 2023/06/27 10:42:38 riastradh Exp $

DISTNAME=		libXxf86dga-1.1.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Library for the XFree86-DGA X extension

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

PKGCONFIG_OVERRIDE+=	xxf86dga.pc.in

.include "../../meta-pkgs/modular-xorg/hacks.mk"

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
