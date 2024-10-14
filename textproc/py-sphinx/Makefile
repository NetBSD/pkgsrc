# $NetBSD: Makefile,v 1.102 2024/10/14 06:46:01 wiz Exp $

DISTNAME=	sphinx-8.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Sphinx/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.sphinx-doc.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.7:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7.14:../../textproc/py-alabaster
DEPENDS+=	${PYPKGPREFIX}-babel>=2.13:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.20:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-imagesize>=1.3:../../graphics/py-imagesize
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.17:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.30.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=2.2:../../textproc/py-snowballstemmer
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-applehelp-[0-9]*:../../textproc/py-sphinxcontrib-applehelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-devhelp-[0-9]*:../../textproc/py-sphinxcontrib-devhelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-htmlhelp>=2.0.0:../../textproc/py-sphinxcontrib-htmlhelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jsmath-[0-9]*:../../textproc/py-sphinxcontrib-jsmath
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-qthelp-[0-9]*:../../textproc/py-sphinxcontrib-qthelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-serializinghtml>=1.1.9:../../textproc/py-sphinxcontrib-serializinghtml
TEST_DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
TEST_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.9:../../devel/py-typing-extensions

USE_LANGUAGES=	# none
USE_TOOLS+=	makeinfo

PYTHON_VERSIONS_INCOMPATIBLE=	39

# as of 8.0.2
# 37 failed, 2126 passed, 30 skipped, 3 warnings

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sphinx-apidoc sphinx-apidoc-${PYVERSSUFFIX} && \
	${MV} sphinx-autogen sphinx-autogen-${PYVERSSUFFIX} && \
	${MV} sphinx-build sphinx-build-${PYVERSSUFFIX} && \
	${MV} sphinx-quickstart sphinx-quickstart-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
