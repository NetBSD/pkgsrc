# $NetBSD: Makefile,v 1.1 2014/06/14 15:01:58 rodent Exp $

DISTNAME=	WTForms-Test-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/W/WTForms-Test/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-test
COMMENT=	Various unit test helpers for WTForms based forms
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.2:../../www/py-wtforms

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
