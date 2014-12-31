# $NetBSD: Makefile,v 1.3 2014/12/31 13:57:34 wiz Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
