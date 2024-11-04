# $NetBSD: Makefile,v 1.3 2024/11/04 12:25:10 adam Exp $

DISTNAME=	rcssmin-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rcssmin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ndparker/rcssmin
COMMENT=	Fast CSS minifier for Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
