# $NetBSD: Makefile,v 1.59 2018/11/13 11:30:40 adam Exp $

DISTNAME=	Sphinx-1.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Sphinx/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7:../../textproc/py-alabaster
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-imagesize-[0-9]*:../../graphics/py-imagesize
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=1.1:../../textproc/py-snowballstemmer
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-websupport-[0-9]*:../../textproc/py-sphinxcontrib-websupport
DEPENDS+=	${PYPKGPREFIX}-six>=1.5:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27" || "${PYPKGPREFIX}" == "py34"
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

TEST_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=		# none
USE_TOOLS+=		makeinfo

REPLACE_PYTHON+=	sphinx/pycode/pgen2/token.py

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} sphinx-apidoc sphinx-apidoc${PYVERSSUFFIX} && \
		${MV} sphinx-autogen sphinx-autogen${PYVERSSUFFIX} && \
		${MV} sphinx-build sphinx-build${PYVERSSUFFIX} && \
		${MV} sphinx-quickstart sphinx-quickstart${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
