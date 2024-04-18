# $NetBSD: Makefile,v 1.64 2024/04/18 09:01:55 wiz Exp $

DISTNAME=	docutils-0.21.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/docutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docutils.sourceforge.io/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-roman>=1.4:../../math/py-roman
DEPENDS+=	${PYPKGPREFIX}-pygments>=0:../../textproc/py-pygments

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	docutils/__main__.py
REPLACE_PYTHON+=	docutils/utils/error_reporting.py
REPLACE_PYTHON+=	docutils/utils/math/math2html.py
REPLACE_PYTHON+=	docutils/utils/smartquotes.py
REPLACE_PYTHON+=	docutils/writers/odf_odt/prepstyles.py
REPLACE_PYTHON+=	docutils/writers/xetex/__init__.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} docutils docutils-${PYVERSSUFFIX} || ${TRUE}
.for bin in rst2html rst2html4 rst2html5 rst2latex rst2man rst2odt \
	rst2pseudoxml rst2s5 rst2xetex rst2xml
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/alltests.py

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
