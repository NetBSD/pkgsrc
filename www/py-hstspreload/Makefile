# $NetBSD: Makefile,v 1.5 2020/03/10 07:35:09 adam Exp $

DISTNAME=	hstspreload-2020.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hstspreload/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sethmlarson/hstspreload
COMMENT=	Chromium HSTS Preload list
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
