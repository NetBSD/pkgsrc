# $NetBSD: Makefile,v 1.14 2001/05/17 08:32:13 abs Exp $
#

DISTNAME=	${PKGNAME}-source
PKGNAME=	fltk-1.0.10
VERS=		${PKGNAME:S/fltk-//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=FLTK/} \
		ftp://ftp.fltk.org/pub/fltk/${VERS}/ \
		ftp://ftp2.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.northamerica.net/pub/ESP/fltk/${VERS}/ \
		ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.kddlabs.co.jp/pub/lang/fltk/${VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces

USE_X11BASE=	# defined
USE_MESA=	# defined
USE_GMAKE=	# defined
USE_LIBTOOL=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${X11PREFIX}/include		# GL/GL.h
MAKE_ENV+=	INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"

# When the API changes and breaks binary-compatibility with the previous
# version, increment the MAJOR by 1 and reset the MINOR to 0.  Otherwise,
# bump the MINOR when a new version comes out.
#
FLTK_MAJOR=	1
FLTK_MINOR=	4
MAKE_ENV+=	FLTK_MAJOR="${FLTK_MAJOR}" FLTK_MINOR="${FLTK_MINOR}"
PLIST_SUBST+=	FLTK_MAJOR=${FLTK_MAJOR} FLTK_MINOR=${FLTK_MINOR}

test:
	@cd ${WRKSRC}/test && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} all

.include "../../mk/bsd.pkg.mk"
