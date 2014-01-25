# $NetBSD: Makefile,v 1.3 2014/01/25 10:30:30 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-werkzeug-docs-${DISTNAME:C/[^-]*-//}

COMMENT=	Python WSGI Utility Library (HTML documentation)

NO_CONFIGURE=	yes
BUILD_TARGET=	documentation

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	${DOCDIR}/html

PLIST_SRC+=	${WRKDIR}/PLIST

.include "../../www/py-werkzeug/Makefile.common"

do-install:
	cd ${WRKSRC}/docs/_build/html \
	    && pax -rwppm . ${DESTDIR}${PREFIX}/${DOCDIR}/html
	${RM} -f ${DESTDIR}${PREFIX}/${DOCDIR}/html/.buildinfo
	cd ${DESTDIR}${PREFIX} \
	    && ${FIND} ${DOCDIR}/html -type f -print > ${WRKDIR}/PLIST

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # sphinx detection broken as of 0.9.4
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../mk/bsd.pkg.mk"
