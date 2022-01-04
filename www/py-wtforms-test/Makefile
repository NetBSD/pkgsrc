# $NetBSD: Makefile,v 1.5 2022/01/04 20:55:39 wiz Exp $

DISTNAME=	WTForms-Test-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-test
COMMENT=	Various unit test helpers for WTForms based forms
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.2:../../www/py-wtforms

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
