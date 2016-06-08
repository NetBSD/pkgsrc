# $NetBSD: Makefile,v 1.6 2016/06/08 17:43:46 wiz Exp $

DISTNAME=	recaptcha-client-1.0.6
PKGNAME=	${PYPKGPREFIX}-recaptcha-1.0.6
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/recaptcha-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cheeseshop.python.org/pypi/recaptcha-client
COMMENT=	Plugin for reCAPTCHA and reCAPTCHA Mailhide
LICENSE=    mit

PYTHON_VERSIONS_INCOMPATIBLE= 33 34 35 # as of 1.0.6

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
