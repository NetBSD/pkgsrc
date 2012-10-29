# $NetBSD: Makefile,v 1.4 2012/10/29 05:06:38 asau Exp $
#

DISTNAME=		libxkbui-1.0.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		xkbui library

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xkbui.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
