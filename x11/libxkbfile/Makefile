# $NetBSD: Makefile,v 1.12 2022/10/18 07:50:27 wiz Exp $

DISTNAME=		libxkbfile-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		The xkbfile Library from modular X.org

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xkbfile.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
