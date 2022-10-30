# $NetBSD: Makefile,v 1.17 2022/10/30 01:08:02 wiz Exp $

DISTNAME=		x11perf-1.6.2
CATEGORIES=		x11
MASTER_SITES=		https://xorg.freedesktop.org/archive/individual/test/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X11 server benchmark suite

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
