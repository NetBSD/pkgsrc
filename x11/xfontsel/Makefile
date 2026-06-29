# $NetBSD: Makefile,v 1.15 2026/06/29 07:25:09 wiz Exp $

DISTNAME=		xfontsel-1.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X font selector

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

LDFLAGS+=		-lintl

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
