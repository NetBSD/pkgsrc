# $NetBSD: Makefile,v 1.16 2005/05/06 01:24:57 xtraeme Exp $
#

DISTNAME=	paragui-1.1.8
CATEGORIES=	x11
MASTER_SITES=	http://savannah.nongnu.org/download/paragui/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.paragui.org/
COMMENT=	Cross-platform high-level application framework and GUI library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	paragui.pc.in
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require native

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
