# $NetBSD: Makefile,v 1.8 2026/07/20 07:05:41 wiz Exp $

DISTNAME=		xkbprint-1.0.8
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Generate printable description of a XKB keyboard description

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
