# $NetBSD: Makefile,v 1.5 2004/01/20 12:27:59 agc Exp $
#

DISTNAME=	mMosaic-3.7.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://perso.enst.fr/~dauphin/mMosaic/
COMMENT=	Modern derivative of NCSA XMosaic

WRKSRC=		${WRKDIR}/mMosaic-src-3.7.2
USE_BUILDLINK2=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mMosaic ${PREFIX}/bin/

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
