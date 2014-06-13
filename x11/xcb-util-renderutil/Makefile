# $NetBSD: Makefile,v 1.4 2014/06/13 07:41:15 wiz Exp $

DISTNAME=	xcb-util-renderutil-0.3.9
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
