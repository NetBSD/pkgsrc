# $NetBSD: Makefile,v 1.8 2022/05/25 15:31:56 wiz Exp $

DISTNAME=	wtforms-recaptcha-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wtforms-recaptcha/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/excieve/wtforms-recaptcha
COMMENT=	Custom WTForms field that handles reCaptcha display and validation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wtforms>=0.6.1:../../www/py-wtforms

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-wtforms

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
