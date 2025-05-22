# $NetBSD: Makefile,v 1.42 2025/05/22 05:59:40 adam Exp $

DISTNAME=	tornado-6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tornado/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://www.tornadoweb.org/
COMMENT=	Fast and non-blocking web framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
