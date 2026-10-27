# $NetBSD: Makefile,v 1.109 2026/10/27 06:20:25 adam Exp $

DISTNAME=	pycurl-7.49.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycurl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pycurl.io/
COMMENT=	Python module interface to the cURL library
LICENSE=	gnu-lgpl-v2.1 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=0:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-test-run-parallel>=0:../../devel/py-test-run-parallel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout

MAKE_ENV+=	PYCURL_SSL_LIBRARY=openssl
INSTALL_ENV+=	PYCURL_SSL_LIBRARY=openssl

BUILDLINK_API_DEPENDS.curl+=	curl>=7.19.0
.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
