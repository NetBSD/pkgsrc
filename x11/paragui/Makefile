# $NetBSD: Makefile,v 1.6 2003/10/11 13:40:20 grant Exp $
#

DISTNAME=		paragui-1.0.4
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://savannah.nongnu.org/download/paragui/stable.pkg/1.0.4/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.paragui.org/
COMMENT=		Cross-platform high-level application framework and GUI library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/src/physfs/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/paragui.pc.in
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require native

.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/physfs/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
