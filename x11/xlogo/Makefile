# $NetBSD: Makefile,v 1.13 2013/06/06 12:55:23 wiz Exp $
#

DISTNAME=		xlogo-1.0.4
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Window System logo

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
