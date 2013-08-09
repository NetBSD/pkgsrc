# $NetBSD: Makefile,v 1.12 2013/08/09 09:23:13 wiz Exp $

DISTNAME=		xset-1.2.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 user preferences utility
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
