# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:56 wiz Exp $

DISTNAME=	isc_dhcp_leases-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
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
