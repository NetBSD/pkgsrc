# $NetBSD: Makefile,v 1.1.1.1 2001/02/16 20:35:55 lukem Exp $
#

DISTNAME=	Pmw.0.8.5
PKGNAME=	py-Pmw-0.8.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmw/}

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://pmw.sourceforge.net/
COMMENT=	python meta widgets

DEPENDS+=       py-Tk>=2.0:../py-Tk

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC
SITE_PKG=	lib/python2.0/site-packages
PYTHON_LIBDIR=	${LOCALBASE}/${SITE_PKG}

do-build:

do-install:
	(cd ${WRKDIR}; ${FIND} Pmw -type d | \
	    sed -e 's,^,${PREFIX}/${SITE_PKG}/,' | xargs ${INSTALL_DATA_DIR})
	(cd ${WRKDIR}; for f in `${FIND} Pmw -type f`; do \
	    ${INSTALL_DATA} $$f ${PREFIX}/${SITE_PKG}/$$f; done)
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} ${SITE_PKG}/Pmw \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${SITE_PKG}/Pmw \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
