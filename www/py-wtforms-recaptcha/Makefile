# $NetBSD: Makefile,v 1.5 2017/09/04 18:08:31 wiz Exp $

DISTNAME=	wtforms-recaptcha-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wtforms-recaptcha/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://bitbucket.org/excieve/wtforms-recaptcha
COMMENT=	Custom WTForms field that handles reCaptcha display and validation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wtforms>=0.6.1:../../www/py-wtforms

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
