# $NetBSD: Makefile,v 1.10 2018/07/07 07:52:08 wiz Exp $

DISTNAME=		libXxf86misc-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Library for the XFree86-Misc X extension

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xxf86misc.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
