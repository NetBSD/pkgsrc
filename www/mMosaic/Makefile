# $NetBSD: Makefile,v 1.1.1.1 2002/08/20 00:39:54 fredb Exp $
#

DISTNAME=	mMosaic-3.7.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://perso.enst.fr/~dauphin/mMosaic/
COMMENT=	Modern derivative of NCSA XMosaic

WRKSRC=		${WRKDIR}/mMosaic-src-3.7.2

USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mMosaic ${PREFIX}/bin/

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
