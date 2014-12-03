# $NetBSD: Makefile,v 1.5 2014/12/03 22:41:09 rodent Exp $

DISTNAME=	phonenumbers-7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/p/phonenumbers/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/daviddrysdale/python-phonenumbers
COMMENT=	Library for formatting, storing and validating phone numbers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	phonenumbers/util.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
