# $NetBSD: Makefile,v 1.7 2025/04/22 21:22:21 wiz Exp $

DISTNAME=	rfc3986-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rfc3986/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rfc3986.readthedocs.io/
COMMENT=	Validating URI References per RFC 3986
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
