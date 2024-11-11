# $NetBSD: Makefile,v 1.36 2024/11/11 07:29:07 wiz Exp $

DISTNAME=	phonenumbers-8.13.43
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/phonenumbers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/daviddrysdale/python-phonenumbers
COMMENT=	Library for formatting, storing and validating phone numbers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	phonenumbers/util.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
