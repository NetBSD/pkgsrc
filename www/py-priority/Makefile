# $NetBSD: Makefile,v 1.6 2026/01/27 09:19:42 wiz Exp $

DISTNAME=	priority-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/priority/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://python-hyper.org/projects/priority/en/stable/
COMMENT=	Pure-Python implementation of the HTTP/2 priority tree
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
