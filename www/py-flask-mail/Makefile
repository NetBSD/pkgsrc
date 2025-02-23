# $NetBSD: Makefile,v 1.11 2025/02/23 21:00:55 wiz Exp $

DISTNAME=	flask_mail-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Mail/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/pallets-eco/flask-mail
COMMENT=	Flask extension for sending email
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
