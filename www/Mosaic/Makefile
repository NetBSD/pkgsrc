# $NetBSD: Makefile,v 1.20 2000/07/29 00:09:59 jlam Exp $
# FreeBSD Id: Makefile,v 1.15 1998/05/27 08:44:56 dburr Exp
#

DISTNAME=		Mosaic-src-2.7b5
PKGNAME=		mosaic-2.7b5
WRKSRC=			${WRKDIR}/Mosaic-src
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		xpm-3.4k:../../graphics/xpm

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 problems

USE_X11BASE=		# defined
USE_MOTIF12=		# defined

GNU_CONFIGURE=		# defined
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
	${MKDIR} ${PREFIX}/share/mosaic

.include "../../mk/bsd.pkg.mk"
