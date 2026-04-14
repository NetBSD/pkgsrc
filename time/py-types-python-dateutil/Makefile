# $NetBSD: Makefile,v 1.21 2026/04/14 12:32:07 adam Exp $

DISTNAME=	types_python_dateutil-2.9.0.20260408
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-python-dateutil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for python-dateutil
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
