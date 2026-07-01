# $NetBSD: Makefile,v 1.16 2026/07/01 08:12:08 wiz Exp $

DISTNAME=		xfontsel-1.1.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X font selector

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
