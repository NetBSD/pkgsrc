# $NetBSD: Makefile,v 1.1 2013/04/01 17:40:25 kleink Exp $

DISTNAME=	Flask-BabelEx-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-BabelEx/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/mrjoes/flask-babelex/
COMMENT=	Adds i18n/l10n support to Flask applications
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-speaklater>=1.2:../../devel/py-speaklater
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.5:../../textproc/py-jinja2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
