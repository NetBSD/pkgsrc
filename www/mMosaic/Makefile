# $NetBSD: Makefile,v 1.6 2004/04/27 05:44:23 snj Exp $
#

DISTNAME=	mMosaic-3.7.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://perso.enst.fr/~dauphin/mMosaic/
COMMENT=	Modern derivative of NCSA XMosaic

WRKSRC=		${WRKDIR}/mMosaic-src-3.7.2
USE_BUILDLINK3=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mMosaic ${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
