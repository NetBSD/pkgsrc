# $NetBSD: Makefile,v 1.2 2026/09/22 09:12:34 adam Exp $

DISTNAME=	yattag-1.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yattag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.yattag.org/
COMMENT=	Generate HTML or XML in a pythonic way
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
