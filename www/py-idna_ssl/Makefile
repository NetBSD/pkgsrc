# $NetBSD: Makefile,v 1.1 2018/02/05 16:38:56 adam Exp $

DISTNAME=	idna_ssl-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/idna_ssl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/idna_ssl
COMMENT=	Patch ssl.match_hostname for Unicode(idna) domains support
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-idna>=2.0:../../www/py-idna

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
