# $NetBSD: Makefile,v 1.10 2024/01/20 10:29:17 adam Exp $

DISTNAME=	Flask-DebugToolbar-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-DebugToolbar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flask-debugtoolbar.readthedocs.io/
COMMENT=	Port of the Django debug toolbar to Flask
LICENSE=	apache-2.0 AND gnu-gpl-v3 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask>=0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-itsdangerous-[0-9]*:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/codemirror/mode/properties/index.html
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/codemirror/mode/properties/properties.js
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/img/tick-red.png
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/img/tick.png

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
