# $NetBSD: Makefile,v 1.9 2017/05/31 08:24:38 adam Exp $

PKGNAME=	${PYPKGPREFIX}-werkzeug-docs-${DISTNAME:C/[^-]*-//}
COMMENT=	Python WSGI Utility Library (HTML documentation)

NO_CONFIGURE=	yes
BUILD_TARGET=	documentation

INSTALLATION_DIRS+=	${DOCDIR}/html

DOCDIR=		share/doc/${PYPKGPREFIX}-${DISTNAME:tl:C/-[^-]*$//}
PLIST_SUBST+=	DOCDIR=${DOCDIR}
PLIST_SRC+=	${WRKDIR}/PLIST

.include "../../www/py-werkzeug/Makefile.common"

do-install:
	cd ${WRKSRC}/docs/_build/html \
	    && pax -rwppm . ${DESTDIR}${PREFIX}/${DOCDIR}/html
	${RM} -f ${DESTDIR}${PREFIX}/${DOCDIR}/html/.buildinfo
	cd ${DESTDIR}${PREFIX} \
	    && ${FIND} ${DOCDIR}/html -type f -print > ${WRKDIR}/PLIST

PYTHON_FOR_BUILD_ONLY=	yes
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.3nb1:../../textproc/py-sphinx

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
