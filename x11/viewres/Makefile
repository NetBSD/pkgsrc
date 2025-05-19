# $NetBSD: Makefile,v 1.9 2025/05/19 06:36:52 wiz Exp $

DISTNAME=		viewres-1.0.8
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Display widget class hierarchy of the Athena Widget Set
LICENSE=		x11

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/meson/build.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
