# $NetBSD: Makefile,v 1.5 2025/04/14 19:31:54 adam Exp $

DISTNAME=	priority-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/priority/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://python-hyper.org/priority/
COMMENT=	Pure-Python implementation of the HTTP/2 priority tree
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
