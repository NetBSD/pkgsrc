# $NetBSD: Makefile,v 1.16 2022/04/19 12:11:10 tnn Exp $

DISTNAME=	Flask-FlatPages-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-FlatPages/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Flask-FlatPages
COMMENT=	Provides flat static pages to a Flask application
LICENSE=	modified-bsd

.include "options.mk"

DEPENDS+=	${PYPKGPREFIX}-flask>1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>5.3.1:../../textproc/py-yaml
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	jinja2 markdown pygments:test

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
