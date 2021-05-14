# $NetBSD: Makefile,v 1.3 2021/05/14 10:19:45 nia Exp $

DISTNAME=	xcb-util-errors-1.0
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	Library for helping debug xcb problems
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config m4
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	xcb-errors.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
