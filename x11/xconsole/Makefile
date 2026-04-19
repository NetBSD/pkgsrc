# $NetBSD: Makefile,v 1.17 2026/04/19 08:01:24 wiz Exp $

DISTNAME=	xconsole-1.1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	X11 client to display console messages

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
