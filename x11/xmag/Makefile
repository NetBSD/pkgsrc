# $NetBSD: Makefile,v 1.16 2026/11/15 07:33:38 wiz Exp $

DISTNAME=		xmag-1.0.9
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Magnify parts of the screen

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/meson/build.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
