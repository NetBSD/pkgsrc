# $NetBSD: Makefile,v 1.7 2000/08/04 03:38:12 jlam Exp $
#

DISTNAME=	fltk-1.0.9-source
PKGNAME=	${DISTNAME:S/-source//}
VERS=		${PKGNAME:S/fltk-//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11
MASTER_SITES=	http://download.sourceforge.net/FLTK/ \
		ftp://ftp.fltk.org/pub/fltk/${VERS}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERS}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fltk.org/

DEPENDS+=	Mesa-*:../../graphics/Mesa

USE_X11BASE=	# defined
USE_GMAKE=	# defined
USE_LIBTOOL=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${X11PREFIX}/include		# GL/GL.h

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
FLTK_MAJOR=	1
FLTK_MINOR=	3
MAKE_ENV+=	FLTK_MAJOR="${FLTK_MAJOR}" FLTK_MINOR="${FLTK_MINOR}"

DOCDIR=		${PREFIX}/share/doc/html/fltk

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/documentation; ${INSTALL_DATA} *.html *.gif *.jpg ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
