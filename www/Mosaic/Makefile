# $NetBSD: Makefile,v 1.26 2001/05/22 09:32:25 wiz Exp $
# FreeBSD Id: Makefile,v 1.15 1998/05/27 08:44:56 dburr Exp
#

DISTNAME=		Mosaic-src-2.7b5
PKGNAME=		mosaic-2.7b5
WRKSRC=			${WRKDIR}/Mosaic-src
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/
COMMENT=		World Wide Web browser

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.11:../../graphics/png

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 problems

USE_X11BASE=		YES
USE_XPM=		YES
USE_MOTIF12=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-zdir=/usr
CONFIGURE_ARGS+=	--with-jpegdir=${LOCALBASE}
CONFIGURE_ARGS+=	--with-pngdir=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

EVAL_PREFIX=		XPMDIR=xpm

CPPFLAGS+=		-I${MOTIFBASE}/include
CPPFLAGS+=		-I${X11BASE}/include
CPPFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-I${XPMDIR}/include
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

.include "../../mk/bsd.pkg.mk"
