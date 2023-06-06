# $NetBSD: Makefile,v 1.19 2023/06/06 12:42:50 riastradh Exp $

DISTNAME=	Flask-FlatPages-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-FlatPages/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Flask-FlatPages
COMMENT=	Provides flat static pages to a Flask application
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.5:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>5.3.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
