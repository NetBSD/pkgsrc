# $NetBSD: Makefile,v 1.5 2022/07/08 14:06:27 wiz Exp $

DISTNAME=	publicsuffix2-2.20191221
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/publicsuffix2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nexb/python-publicsuffix2
COMMENT=	Public suffix for a domain name using the Public Suffix List
LICENSE=	mit AND mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
