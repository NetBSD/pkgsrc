# $NetBSD: Makefile,v 1.15 2026/05/25 19:19:29 wiz Exp $

DISTNAME=		xlsclients-1.1.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X client listing utility
LICENSE=		mit

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
