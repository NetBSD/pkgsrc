# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:29 tsarna Exp $
# FreeBSD Id: Makefile,v 1.15 1998/05/27 08:44:56 dburr Exp
#

DISTNAME=       Mosaic-src-2.7b5
PKGNAME=        mosaic-2.7b5
CATEGORIES=     www
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/Web/Mosaic/Unix/source/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.ncsa.uiuc.edu/SDG/Software/Mosaic/

DEPENDS=	jpeg-6b:../../graphics/jpeg \
		png-1.0.2:../../graphics/png \
		xpm-3.4k:../../graphics/xpm

USE_X11=	yes
USE_MOTIF=	yes

WRKSRC=		${WRKDIR}/Mosaic-src

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
CONFIGURE_ARGS=	--with-zdir=/usr --with-jpegdir=${LOCALBASE} --with-pngdir=${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Mosaic ${PREFIX}/bin
	${LN} -sf Mosaic ${PREFIX}/bin/mosaic
	${INSTALL_DATA} ${WRKSRC}/app-defaults.color ${PREFIX}/lib/X11/app-defaults/Mosaic

.include "../../mk/bsd.pkg.mk"
