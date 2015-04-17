# $NetBSD: Makefile,v 1.1 2015/04/17 19:54:46 wiz Exp $

DISTNAME=		libXpresent-1.0.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xlib-compatible API for the Present extension

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xpresent.pc.in
GNU_CONFIGURE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/presentproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
