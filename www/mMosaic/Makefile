# $NetBSD: Makefile,v 1.8 2005/03/06 16:56:17 fredb Exp $
#

DISTNAME=	mMosaic-3.7.2
PKGREVISION=	1
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKEFLAGS+=	sysconfigflags='-DNETBSD -DMOTIF1_2'

.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
MAKEFLAGS+=	sysconfigflags='-DFreeBSD -DMOTIF1_2'

.elif ${OPSYS} == "Linux"
MAKEFLAGS+=	sysconfigflags='-DLINUX -Dlinux -DMOTIF1_2'

.elif ${OPSYS:MIRIX*} != ""
MAKEFLAGS+=	sysconfigflags='-DSVR4 -DIRIX -DMOTIF1_2'

.endif

.include "../../mk/bsd.pkg.mk"
