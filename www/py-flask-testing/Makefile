# $NetBSD: Makefile,v 1.3 2014/08/07 02:29:08 rodent Exp $

DISTNAME=	Flask-Testing-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/F/Flask-Testing/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/jarus/flask-testing
COMMENT=	Unit testing for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "options.mk"

EGG_NAME=	${DISTNAME:S,-,_,}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
