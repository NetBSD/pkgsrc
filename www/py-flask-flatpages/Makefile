# $NetBSD: Makefile,v 1.22 2025/01/02 14:23:32 adam Exp $

DISTNAME=	flask_flatpages-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-FlatPages/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Flask-FlatPages
COMMENT=	Provides flat static pages to a Flask application
LICENSE=	modified-bsd

WHEEL_NAME=	${DISTNAME:S/flask_flatpages/Flask_FlatPages/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flask>1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.5:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>5.3.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
