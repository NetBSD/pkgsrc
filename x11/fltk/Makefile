# $NetBSD: Makefile,v 1.6 2000/06/01 11:23:44 rh Exp $
#

DISTNAME=	fltk-1.0.7-source
PKGNAME=	${DISTNAME:S/-source//}
VERS=		${PKGNAME:S/fltk-//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.fltk.org/pub/fltk/${VERS}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERS}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fltk.org/

DEPENDS+=	Mesa-*:../../graphics/Mesa

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_PKGLIBTOOL=	yes
GNU_CONFIGURE=	yes

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
FLTK_MAJOR=	1
FLTK_MINOR=	2
MAKE_ENV+=	FLTK_MAJOR="${FLTK_MAJOR}" FLTK_MINOR="${FLTK_MINOR}"

DOCDIR=		${PREFIX}/share/doc/fltk

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
