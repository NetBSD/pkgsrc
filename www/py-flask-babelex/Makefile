# $NetBSD: Makefile,v 1.10 2022/04/19 12:10:19 tnn Exp $

DISTNAME=	Flask-BabelEx-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-BabelEx/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/mrjoes/flask-babelex/
COMMENT=	Adds i18n and l10n support for Flask based on Babel and pytz
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES=	jinja2

DEPENDS+=	${PYPKGPREFIX}-babel>=1.0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-speaklater>=1.2:../../devel/py-speaklater

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
