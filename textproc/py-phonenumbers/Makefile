# $NetBSD: Makefile,v 1.8 2017/01/12 00:52:25 rodent Exp $

DISTNAME=	phonenumbers-8.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/phonenumbers/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/daviddrysdale/python-phonenumbers
COMMENT=	Library for formatting, storing and validating phone numbers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	phonenumbers/util.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
