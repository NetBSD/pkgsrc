# $NetBSD: Makefile,v 1.1.1.1 2000/07/30 00:19:55 tsarna Exp $
#

DISTNAME=	wxPython-2.2.0
PKGNAME=	py-wxWindows-2.2.0
CATEGORIES=	x11
MASTER_SITES=	http://alldunn.com/wxPython/dist/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://wxpython.org/

DEPENDS+=       python-1.5.2:../../lang/python
DEPENDS+=       wxGTK-2.2.0:../../x11/wxGTK

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC
SITE_PKG=	lib/python1.5/site-packages
PYTHON_LIBDIR=	${LOCALBASE}/${SITE_PKG}

USE_GMAKE=	yes

do-build:
	(cd ${WRKSRC}/src; WXWIN=${PREFIX} \
	${PREFIX}/bin/python ../distrib/build.py -b)

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}/src; gmake install)
	(cd ${PYTHON_LIBDIR}/wxPython; \
	${PREFIX}/bin/python ${PREFIX}/lib/python1.5/compileall.py . \
	${PREFIX}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py . )
	(cd ${PREFIX}; ${FIND} ${SITE_PKG}/wxPython \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${SITE_PKG}/wxPython \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
