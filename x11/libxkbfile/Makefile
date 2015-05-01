# $NetBSD: Makefile,v 1.8 2015/05/01 08:41:32 wiz Exp $

DISTNAME=		libxkbfile-1.0.9
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

.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
