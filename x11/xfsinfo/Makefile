# $NetBSD: Makefile,v 1.8 2025/07/27 05:59:37 wiz Exp $

DISTNAME=	xfsinfo-1.0.8
CATEGORIES=	x11 fonts
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Utility for displaying information about an X font server
LICENSE=	x11 # AND others

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
