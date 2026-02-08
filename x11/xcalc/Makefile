# $NetBSD: Makefile,v 1.19 2026/02/08 06:39:37 wiz Exp $

DISTNAME=		xcalc-1.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Scientific calculator for X
LICENSE=		mit

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
