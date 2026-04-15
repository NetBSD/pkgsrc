# $NetBSD: Makefile,v 1.1 2026/04/15 08:43:25 kikadf Exp $

DISTNAME=	wlsunset-0.4.0
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=kennylevinsen/}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://sr.ht/~kennylevinsen/wlsunset/
COMMENT=	Day/night gamma adjustments for Wayland compositors
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
