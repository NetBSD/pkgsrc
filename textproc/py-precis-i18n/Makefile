# $NetBSD: Makefile,v 1.13 2025/10/16 14:36:06 adam Exp $

DISTNAME=	precis_i18n-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/precis-i18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/byllyfish/precis_i18n
COMMENT=	PRECIS-i18n: Internationalized Usernames and Passwords
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
