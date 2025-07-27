# $NetBSD: Makefile,v 1.12 2025/07/27 05:56:15 wiz Exp $

DISTNAME=	xdriinfo-1.0.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	X.org DRI information utility

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
### Prior to this revision, the r300 driver did not export a symbol
### xdriinfo needs to access its configuration data.
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=7.0.4.1nb3
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
