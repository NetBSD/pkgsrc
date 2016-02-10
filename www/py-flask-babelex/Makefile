# $NetBSD: Makefile,v 1.6 2016/02/10 10:20:10 kleink Exp $

DISTNAME=	Flask-BabelEx-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-BabelEx/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/mrjoes/flask-babelex/
COMMENT=	Adds i18n and l10n support for Flask based on Babel and pytz
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-babel>=1.0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-speaklater>=1.2:../../devel/py-speaklater
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.5:../../textproc/py-jinja2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
