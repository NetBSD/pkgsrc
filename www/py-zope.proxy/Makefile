# $NetBSD: Makefile,v 1.17 2025/03/05 11:01:13 wiz Exp $

DISTNAME=	zope_proxy-6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.proxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.proxy
COMMENT=	Generic Transparent Proxies
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
