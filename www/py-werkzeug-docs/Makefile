# $NetBSD: Makefile,v 1.13 2019/10/21 22:11:34 adam Exp $

PKGNAME=	${PYPKGPREFIX}-werkzeug-docs-${DISTNAME:C/[^-]*-//}
COMMENT=	Python WSGI Utility Library (HTML documentation)

TOOL_DEPENDS+=	${PYPKGPREFIX}-pallets-sphinx-themes-[0-9]*:../../textproc/py-pallets-sphinx-themes
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-issues-[0-9]*:../../textproc/py-sphinx-issues
TOOL_DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
BUILD_TARGET=	html
BUILD_DIRS=	docs

INSTALLATION_DIRS+=	${DOCDIR}/html

DOCDIR=		share/doc/${PYPKGPREFIX}-${DISTNAME:tl:C/-[^-]*$//}
PLIST_SUBST+=	DOCDIR=${DOCDIR}
PLIST_SRC+=	${WRKDIR}/PLIST

.include "../../www/py-werkzeug/Makefile.common"

do-install:
	cd ${WRKSRC}/docs/_build/html && \
		${PAX} -rwppm . ${DESTDIR}${PREFIX}/${DOCDIR}/html
	${RM} -f ${DESTDIR}${PREFIX}/${DOCDIR}/html/.buildinfo
	cd ${DESTDIR}${PREFIX} && \
		${FIND} ${DOCDIR}/html -type f -print > ${WRKDIR}/PLIST

PYTHON_FOR_BUILD_ONLY=	yes

MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
