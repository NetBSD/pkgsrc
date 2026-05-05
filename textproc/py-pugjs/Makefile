# $NetBSD: Makefile,v 1.3 2026/05/05 18:08:23 adam Exp $

DISTNAME=	pypugjs-6.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypugjs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kakulukia/pypugjs
COMMENT=	PugJS syntax template adapter for Django, Jinja2, Mako and Tornado templates
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer>=0:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-django>=0:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-icecream>=0:../../misc/py-icecream
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=0:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-mako>=0:../../devel/py-mako
#TEST_DEPENDS+=	${PYPKGPREFIX}-pyramid>=1.5:../../wip/py-pyramid
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=0:../../www/py-tornado
#TEST_DEPENDS+=	# TODO: pyramid-mako>=0

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
