# $NetBSD: Makefile,v 1.9 2024/12/31 09:59:02 adam Exp $

DISTNAME=	sphobjinv-2.3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphobjinv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bskinn/sphobjinv
COMMENT=	Toolkit for manipulation and inspection of Sphinx objects.inv files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.0:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-dictdiffer>=0:../../devel/py-dictdiffer
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-stdio-mgr>=0:../../devel/py-stdio-mgr
TEST_DEPENDS+=	${PYPKGPREFIX}-test-check>=0:../../devel/py-test-check

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} sphobjinv sphobjinv-${PYVERSSUFFIX} || ${TRUE}

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
