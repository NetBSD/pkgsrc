# $NetBSD: Makefile,v 1.14 1999/09/04 23:25:03 tron Exp $
# FreeBSD Id: Makefile,v 1.15 1998/05/27 08:44:56 dburr Exp
#

DISTNAME=		Mosaic-src-2.7b5
PKGNAME=		mosaic-2.7b5
WRKSRC=			${WRKDIR}/Mosaic-src
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/

DEPENDS=		jpeg-6b:../../graphics/jpeg \
			png-1.0.3:../../graphics/png \
			xpm-3.4k:../../graphics/xpm

NOT_FOR_PLATFORM=	*-*-alpha	#LP64 problems

USE_X11BASE=		yes
USE_MOTIF=		yes

GNU_CONFIGURE=		yes

LDFLAGS+=		-L${X11BASE}/LessTif/Motif1.2/lib -L${X11BASE}/lib

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/LessTif/Motif1.2/include -I${X11BASE}/include -Dunix"
CONFIGURE_ARGS=		--with-zdir=/usr --with-jpegdir=${LOCALBASE} --with-pngdir=${LOCALBASE}

post-configure:
	@${ECHO} '' >>${WRKSRC}/config.h
	@${ECHO} '#define PREFIX "${PREFIX}"' >>${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Mosaic ${PREFIX}/bin
	${LN} -sf Mosaic ${PREFIX}/bin/mosaic
	${INSTALL_DATA} ${WRKSRC}/app-defaults.color ${PREFIX}/lib/X11/app-defaults/Mosaic
	${MKDIR} ${PREFIX}/share/mosaic

.include "../../mk/bsd.pkg.mk"
