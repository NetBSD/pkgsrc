# $NetBSD: Makefile,v 1.34.2.2 2002/06/21 23:05:46 jlam Exp $
# FreeBSD Id: Makefile,v 1.15 1998/05/27 08:44:56 dburr Exp
#

DISTNAME=		Mosaic-src-2.7b5
PKGNAME=		mosaic-2.7b5
PKGREVISION=		1
WRKSRC=			${WRKDIR}/Mosaic-src
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/
COMMENT=		World Wide Web browser

LICENSE=		mosaic-license

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 problems

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_MOTIF12=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-jpegdir=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-pngdir=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-zdir=${BUILDLINK_PREFIX.zlib}

CPPFLAGS+=		-Dunix

post-configure:
	@${ECHO} '' >>${WRKSRC}/config.h
	@${ECHO} '#define PREFIX "${PREFIX}"' >>${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Mosaic ${PREFIX}/bin
	${LN} -sf Mosaic ${PREFIX}/bin/mosaic
	${INSTALL_DATA} ${WRKSRC}/app-defaults.color \
		${PREFIX}/lib/X11/app-defaults/Mosaic
	${INSTALL_DATA_DIR} ${PREFIX}/share/mosaic

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
