# $NetBSD: Makefile,v 1.12 2026/01/25 22:14:55 wiz Exp $

DISTNAME=		xkill-1.0.7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Kill X clients

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
