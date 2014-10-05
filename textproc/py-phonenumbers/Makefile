# $NetBSD: Makefile,v 1.4 2014/10/05 22:08:30 rodent Exp $

DISTNAME=	phonenumbers-6.3.0
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
