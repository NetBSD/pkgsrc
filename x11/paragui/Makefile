# $NetBSD: Makefile,v 1.36 2015/04/25 14:25:14 tnn Exp $
#

DISTNAME=		paragui-1.0.4
PKGREVISION=		22
CATEGORIES=		x11
MASTER_SITES=		http://savannah.nongnu.org/download/paragui/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.paragui.org/
COMMENT=		Cross-platform high-level application framework and GUI library

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	paragui.pc.in
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require native

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
