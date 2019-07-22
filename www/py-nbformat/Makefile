# $NetBSD: Makefile,v 1.3 2019/07/22 08:42:50 nia Exp $

DISTNAME=	nbformat-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbformat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter Notebook format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.4:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1:../../devel/py-traitlets
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} jupyter-trust jupyter-trust${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
