# $NetBSD: Makefile,v 1.14 2026/07/10 16:07:29 wiz Exp $

DISTNAME=		xrefresh-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Refresher

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
