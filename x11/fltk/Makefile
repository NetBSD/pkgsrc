# $NetBSD: Makefile,v 1.1.1.1 1999/05/06 07:23:28 sakamoto Exp $
#

DISTNAME=	fltk-1.0.2-source
PKGNAME=	fltk-1.0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/1.0.2/ \
		ftp://ftp2.easysw.com/pub/fltk/1.0.2/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/1.0.2/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/1.0.2/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/1.0.2/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://fltk.easysw.com/

DEPENDS+=	Mesa-3.0:../../graphics/Mesa

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
