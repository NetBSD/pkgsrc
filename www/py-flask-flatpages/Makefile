# $NetBSD: Makefile,v 1.20 2024/01/20 10:24:33 adam Exp $

DISTNAME=	Flask-FlatPages-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-FlatPages/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/SimonSapin/Flask-FlatPages
COMMENT=	Provides flat static pages to a Flask application
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-flask>1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.5:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>5.3.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
