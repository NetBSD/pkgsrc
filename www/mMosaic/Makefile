# $NetBSD: Makefile,v 1.32 2016/03/12 21:53:39 tnn Exp $
#

DISTNAME=	mMosaic-3.7.2
PKGREVISION=	11
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.enst.fr/pub/mbone/mMosaic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perso.telecom-paristech.fr/~dauphin/mMosaic/
COMMENT=	Modern derivative of NCSA XMosaic

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/mMosaic-src-3.7.2

INSTALLATION_DIRS=	bin

MAKE_FLAGS.DragonFly+=	sysconfigflags='-DFreeBSD -DMOTIF1_2'
MAKE_FLAGS.FreeBSD+=	sysconfigflags='-DFreeBSD -DMOTIF1_2'
MAKE_FLAGS.IRIX+=	sysconfigflags='-DSVR4 -DIRIX -DMOTIF1_2'
MAKE_FLAGS.Linux+=	sysconfigflags='-DLINUX -Dlinux -DMOTIF1_2'
MAKE_FLAGS.NetBSD+=	sysconfigflags='-DNETBSD -DMOTIF1_2'

BUILDLINK_TRANSFORM.Darwin+=	opt:-shared:-c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mMosaic ${DESTDIR}${PREFIX}/bin/

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
