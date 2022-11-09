# $NetBSD: Makefile,v 1.11 2022/11/09 13:14:19 joerg Exp $

DISTNAME=		ico-1.0.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Animate icosahedron or other polyhedrons

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PTHREAD_AUTO_VARS=	yes

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
