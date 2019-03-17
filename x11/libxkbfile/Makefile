# $NetBSD: Makefile,v 1.10 2019/03/17 08:13:53 wiz Exp $

DISTNAME=		libxkbfile-1.1.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		The xkbfile Library from modular X.org

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xkbfile.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
