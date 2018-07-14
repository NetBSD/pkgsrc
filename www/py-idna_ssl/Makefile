# $NetBSD: Makefile,v 1.3 2018/07/14 18:59:31 adam Exp $

DISTNAME=	idna-ssl-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/idna_ssl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/idna_ssl
COMMENT=	Patch ssl.match_hostname for Unicode(idna) domains support
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-idna>=2.0:../../www/py-idna
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
