# $NetBSD: Makefile,v 1.4 2022/10/19 08:29:35 wiz Exp $

DISTNAME=	xcb-util-errors-1.0.1
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	Library for helping debug xcb problems
LICENSE=	x11

TOOL_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config m4
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	xcb-errors.pc.in

.include "../../lang/python/tool.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
