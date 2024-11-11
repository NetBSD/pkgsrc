# $NetBSD: Makefile,v 1.37 2024/11/11 07:29:28 wiz Exp $

DISTNAME=	tornado-6.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tornado/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://www.tornadoweb.org/
COMMENT=	Fast and non-blocking web framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
