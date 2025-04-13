# $NetBSD: Makefile,v 1.6 2025/04/13 00:33:30 gutteridge Exp $

DISTNAME=	isc_dhcp_leases-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isc_dhcp_leases/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/MartijnBraam/python-isc-dhcp-leases
COMMENT=	Python module for parsing ISC dhcpd lease files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
