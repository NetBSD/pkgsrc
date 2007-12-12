# $NetBSD: Makefile,v 1.18 2007/12/12 20:42:31 wiz Exp $
#

DISTNAME=	mMosaic-3.7.2
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/

MAINTAINER=	pkgsrc-users@NetBSD.org
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

.elif ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rename:-shared:-c
.endif

.include "../../x11/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
