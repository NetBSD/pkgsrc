# $NetBSD: Makefile,v 1.16 2019/05/29 21:05:10 adam Exp $

DISTNAME=	phonenumbers-8.10.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/phonenumbers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/daviddrysdale/python-phonenumbers
COMMENT=	Library for formatting, storing and validating phone numbers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	phonenumbers/util.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
