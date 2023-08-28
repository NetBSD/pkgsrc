# $NetBSD: Makefile,v 1.1 2023/08/28 10:33:08 gdt Exp $

DISTNAME=	yattag-1.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yattag/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.yattag.org/
COMMENT=	Generate HTML or XML in a pythonic way
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
