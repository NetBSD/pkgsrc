# $NetBSD: Makefile,v 1.23 2026/11/10 09:15:52 adam Exp $

DISTNAME=	zope_proxy-7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.proxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.proxy
COMMENT=	Generic Transparent Proxies
LICENSE=	zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=0:../../devel/py-zope.interface

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
