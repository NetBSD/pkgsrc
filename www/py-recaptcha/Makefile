# $NetBSD: Makefile,v 1.7 2016/07/09 13:04:15 wiz Exp $

DISTNAME=	recaptcha-client-1.0.6
PKGNAME=	${PYPKGPREFIX}-recaptcha-1.0.6
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/recaptcha-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cheeseshop.python.org/pypi/recaptcha-client
COMMENT=	Plugin for reCAPTCHA and reCAPTCHA Mailhide
LICENSE=    mit

PYTHON_VERSIONS_INCOMPATIBLE= 34 35 # as of 1.0.6

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
