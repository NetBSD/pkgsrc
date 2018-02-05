# $NetBSD: Makefile,v 1.46 2018/02/05 13:10:59 adam Exp $

DISTNAME=	Sphinx-1.6.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Sphinx/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7:../../textproc/py-alabaster
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-imagesize-[0-9]*:../../graphics/py-imagesize
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=1.1:../../textproc/py-snowballstemmer
DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-websupport-[0-9]*:../../textproc/py-sphinxcontrib-websupport
DEPENDS+=	${PYPKGPREFIX}-six>=1.5:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27" || "${PYPKGPREFIX}" == "py34"
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

BUILD_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson

USE_LANGUAGES=		# none
USE_TOOLS+=		makeinfo

REPLACE_PYTHON+=	sphinx/pycode/pgen2/token.py

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} run.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} sphinx-apidoc sphinx-apidoc${PYVERSSUFFIX} && \
		${MV} sphinx-autogen sphinx-autogen${PYVERSSUFFIX} && \
		${MV} sphinx-build sphinx-build${PYVERSSUFFIX} && \
		${MV} sphinx-quickstart sphinx-quickstart${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
