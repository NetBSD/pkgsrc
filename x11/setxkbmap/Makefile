# $NetBSD: Makefile,v 1.16 2026/03/29 10:59:56 wiz Exp $

DISTNAME=	setxkbmap-1.3.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Set the keyboard map using the X Keyboard Extension

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
