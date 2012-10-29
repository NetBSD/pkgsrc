# $NetBSD: Makefile,v 1.3 2012/10/29 05:06:59 asau Exp $
#

DISTNAME=	xcb-util-renderutil-0.3.8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	Convenience functions for the Render extension
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	renderutil/xcb-renderutil.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
