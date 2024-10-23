# $NetBSD: Makefile,v 1.11 2024/10/23 09:37:28 adam Exp $

DISTNAME=	flask_debugtoolbar-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-DebugToolbar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flask-debugtoolbar.readthedocs.io/
COMMENT=	Port of the Django debug toolbar to Flask
LICENSE=	apache-2.0 AND gnu-gpl-v3 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-flask>=2.3.0:../../www/py-flask

USE_LANGUAGES=	# none

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/codemirror/mode/properties/index.html
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/codemirror/mode/properties/properties.js
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/img/tick-red.png
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/img/tick.png

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
