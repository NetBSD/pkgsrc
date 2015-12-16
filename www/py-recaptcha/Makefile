# $NetBSD: Makefile,v 1.5 2015/12/16 06:03:39 darcy Exp $

DISTNAME=	recaptcha-client-1.0.6
PKGNAME=	${PYPKGPREFIX}-recaptcha-1.0.6
CATEGORIES=	www devel python
MASTER_SITES=	http://pypi.python.org/packages/source/r/recaptcha-client/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cheeseshop.python.org/pypi/recaptcha-client
COMMENT=	Plugin for reCAPTCHA and reCAPTCHA Mailhide
LICENSE=    mit

PYTHON_VERSIONS_INCOMPATIBLE= 33 34 35 # as of 1.0.6

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
