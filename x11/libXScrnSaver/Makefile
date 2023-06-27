# $NetBSD: Makefile,v 1.19 2023/06/27 10:29:39 riastradh Exp $

DISTNAME=		libXScrnSaver-1.2.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X11 Screen Saver Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

PKGCONFIG_OVERRIDE+=	xscrnsaver.pc.in

X11_LIB_NAME?=		libXScrnSaver
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
