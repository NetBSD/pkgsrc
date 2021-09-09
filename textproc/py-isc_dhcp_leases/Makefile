# $NetBSD: Makefile,v 1.2 2021/09/09 00:21:13 gutteridge Exp $

DISTNAME=	isc_dhcp_leases-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isc_dhcp_leases/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/MartijnBraam/python-isc-dhcp-leases
COMMENT=	Python module for parsing ISC dhcpd lease files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
