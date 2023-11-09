# $NetBSD: Makefile,v 1.10 2023/11/09 14:32:26 adam Exp $

DISTNAME=	precis_i18n-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/precis-i18n/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/byllyfish/precis_i18n
COMMENT=	PRECIS-i18n: Internationalized Usernames and Passwords
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
