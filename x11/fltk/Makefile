# $NetBSD: Makefile,v 1.3 1999/09/29 22:58:45 tron Exp $
#

DISTNAME=	fltk-1.0.3-source
PKGNAME=	fltk-1.0.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/1.0.3/ \
		ftp://ftp2.easysw.com/pub/fltk/1.0.3/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/1.0.3/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/1.0.3/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/1.0.3/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fltk.easysw.com/

DEPENDS+=	Mesa-*:../../graphics/Mesa

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}/
DOCDIR=		${PREFIX}/share/doc/fltk

post-install:
	@${INSTALL_DATA_DIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/documentation/* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
