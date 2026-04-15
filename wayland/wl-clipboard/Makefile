# $NetBSD: Makefile,v 1.1 2026/04/15 07:49:38 kikadf Exp $

DISTNAME=	wl-clipboard-2.3.0
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=bugaevc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/bugaevc/wl-clipboard
COMMENT=	Command-line copy/paste utilities for Wayland
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
