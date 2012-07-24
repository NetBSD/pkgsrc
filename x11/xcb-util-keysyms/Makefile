# $NetBSD: Makefile,v 1.1 2012/07/24 18:02:07 drochner Exp $
#

DISTNAME=	xcb-util-keysyms-0.3.9
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB Utilities
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	xcb-keysyms.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
