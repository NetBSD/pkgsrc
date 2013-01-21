# $NetBSD: Makefile,v 1.7 2013/01/21 13:16:59 wiz Exp $
#

DISTNAME=		ico-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Animate icosahedron or other polyhedrons

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PTHREAD_AUTO_VARS=	yes

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
