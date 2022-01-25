# $NetBSD: Makefile,v 1.85 2022/01/25 09:20:30 wiz Exp $

DISTNAME=	Sphinx-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Sphinx/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.sphinx-doc.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7:../../textproc/py-alabaster
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.14:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-imagesize-[0-9]*:../../graphics/py-imagesize
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=1.1:../../textproc/py-snowballstemmer
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-applehelp-[0-9]*:../../textproc/py-sphinxcontrib-applehelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-devhelp-[0-9]*:../../textproc/py-sphinxcontrib-devhelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-htmlhelp>=2.0.0:../../textproc/py-sphinxcontrib-htmlhelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jsmath-[0-9]*:../../textproc/py-sphinxcontrib-jsmath
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-qthelp-[0-9]*:../../textproc/py-sphinxcontrib-qthelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-serializinghtml>=1.1.5:../../textproc/py-sphinxcontrib-serializinghtml
TEST_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none
USE_TOOLS+=	makeinfo

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.4.0:../../devel/py-importlib-metadata
.endif

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sphinx-apidoc sphinx-apidoc-${PYVERSSUFFIX} && \
	${MV} sphinx-autogen sphinx-autogen-${PYVERSSUFFIX} && \
	${MV} sphinx-build sphinx-build-${PYVERSSUFFIX} && \
	${MV} sphinx-quickstart sphinx-quickstart-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
