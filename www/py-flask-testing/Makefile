# $NetBSD: Makefile,v 1.2 2014/05/13 17:08:45 joerg Exp $

DISTNAME=	Flask-Testing-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME:S,-,_,}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-Testing/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/jarus/flask-testing
COMMENT=	Unit testing for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
