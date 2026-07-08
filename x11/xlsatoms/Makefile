# $NetBSD: Makefile,v 1.8 2026/07/08 07:26:36 wiz Exp $

DISTNAME=	xlsatoms-1.1.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Lists the interned atoms defined on an X11 server
LICENSE=	x11

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
