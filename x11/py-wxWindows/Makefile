# $NetBSD: Makefile,v 1.7 2000/11/12 20:38:38 tsarna Exp $
#

DISTNAME=	wxPython-2.2.2
PKGNAME=	py-wxWindows-2.2.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://wxpython.org/

DEPENDS+=       python>=2.0:../../lang/python
DEPENDS+=       wxGTK>=2.2.2:../../x11/wxGTK

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC
SITE_PKG=	lib/python2.0/site-packages
PYTHON_LIBDIR=	${LOCALBASE}/${SITE_PKG}

USE_GMAKE=	yes

BUILD_OPTS=	BUILD_GLCANVAS=0

do-build:
	(cd ${WRKSRC}; ${PREFIX}/bin/python setup.py ${BUILD_OPTS} build)

do-install:
	(cd ${WRKSRC}; ${PREFIX}/bin/python setup.py install)
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PYTHON_LIBDIR}/wxPython; \
	${PREFIX}/bin/python ${PREFIX}/lib/python2.0/compileall.py . ; \
	${PREFIX}/bin/python -O ${PREFIX}/lib/python2.0/compileall.py . )
	(cd ${PREFIX}; ${FIND} ${SITE_PKG}/wxPython \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${SITE_PKG}/wxPython \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
