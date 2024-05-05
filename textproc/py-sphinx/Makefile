# $NetBSD: Makefile,v 1.98 2024/05/05 20:28:45 wiz Exp $

DISTNAME=	sphinx-7.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Sphinx/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.sphinx-doc.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.7:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7.14:../../textproc/py-alabaster
DEPENDS+=	${PYPKGPREFIX}-babel>=2.9:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.18.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-imagesize>=1.3:../../graphics/py-imagesize
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.14:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=2.0:../../textproc/py-snowballstemmer
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-applehelp-[0-9]*:../../textproc/py-sphinxcontrib-applehelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-devhelp-[0-9]*:../../textproc/py-sphinxcontrib-devhelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-htmlhelp>=2.0.0:../../textproc/py-sphinxcontrib-htmlhelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jsmath-[0-9]*:../../textproc/py-sphinxcontrib-jsmath
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-qthelp-[0-9]*:../../textproc/py-sphinxcontrib-qthelp
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-serializinghtml>=1.1.9:../../textproc/py-sphinxcontrib-serializinghtml
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

USE_LANGUAGES=	# none
USE_TOOLS+=	makeinfo

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.8.0:../../devel/py-importlib-metadata
.endif

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=0:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sphinx-apidoc sphinx-apidoc-${PYVERSSUFFIX} && \
	${MV} sphinx-autogen sphinx-autogen-${PYVERSSUFFIX} && \
	${MV} sphinx-build sphinx-build-${PYVERSSUFFIX} && \
	${MV} sphinx-quickstart sphinx-quickstart-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
