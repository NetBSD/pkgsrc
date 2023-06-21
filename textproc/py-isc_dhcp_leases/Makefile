# $NetBSD: Makefile,v 1.5 2023/06/21 22:20:22 gutteridge Exp $

DISTNAME=	isc_dhcp_leases-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isc_dhcp_leases/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/MartijnBraam/python-isc-dhcp-leases
COMMENT=	Python module for parsing ISC dhcpd lease files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
