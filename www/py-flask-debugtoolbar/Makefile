# $NetBSD: Makefile,v 1.8 2022/01/04 20:55:26 wiz Exp $

DISTNAME=	Flask-DebugToolbar-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-DebugToolbar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flask-debugtoolbar.rtfd.org/
COMMENT=	Port of the Django debug toolbar to Flask
LICENSE=	apache-2.0 AND gnu-gpl-v3 AND gnu-lgpl-v2.1 AND mit AND modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flask>0.8:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-itsdangerous-[0-9]*:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

USE_LANGUAGES=	# none

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/codemirror/mode/properties/index.html
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/codemirror/mode/properties/properties.js
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/img/tick-red.png
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_debugtoolbar/static/img/tick.png

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
