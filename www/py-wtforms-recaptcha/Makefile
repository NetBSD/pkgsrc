# $NetBSD: Makefile,v 1.2 2014/07/16 23:30:01 rodent Exp $

DISTNAME=	wtforms-recaptcha-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/w/wtforms-recaptcha/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/excieve/wtforms-recaptcha
COMMENT=	Custom WTForms field that handles reCaptcha display and validation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wtforms>=0.6.1:../../www/py-wtforms

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
