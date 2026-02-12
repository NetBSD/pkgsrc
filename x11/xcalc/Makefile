# $NetBSD: Makefile,v 1.20 2026/02/12 07:37:32 wiz Exp $

DISTNAME=		xcalc-1.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Scientific calculator for X
LICENSE=		mit

USE_TOOLS+=		pkg-config
MESON_ARGS+=		-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/meson/build.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
