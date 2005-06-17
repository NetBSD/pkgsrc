# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:41 jlam Exp $
#

DISTNAME=	mMosaic-3.7.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://perso.enst.fr/~dauphin/mMosaic/
COMMENT=	Modern derivative of NCSA XMosaic

WRKSRC=		${WRKDIR}/mMosaic-src-3.7.2

INSTALLATION_DIRS=	bin

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
