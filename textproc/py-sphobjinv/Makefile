# $NetBSD: Makefile,v 1.5 2023/11/07 22:38:07 wiz Exp $

DISTNAME=	sphobjinv-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphobjinv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bskinn/sphobjinv
COMMENT=	Toolkit for manipulation and inspection of Sphinx objects.inv files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.0:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-dictdiffer>=0:../../devel/py-dictdiffer
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-stdio-mgr>=0:../../devel/py-stdio-mgr
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-check>=0:../../devel/py-test-check

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} sphobjinv sphobjinv-${PYVERSSUFFIX} || ${TRUE}

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
