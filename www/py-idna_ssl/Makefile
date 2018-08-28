# $NetBSD: Makefile,v 1.4 2018/08/28 13:44:00 sevan Exp $

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

.include "../../lang/python/pyversion.mk"

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
