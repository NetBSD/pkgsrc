# $NetBSD: Makefile,v 1.3 2019/12/19 22:25:45 joerg Exp $

DISTNAME=	publicsuffix2-2.20190812
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/publicsuffix2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nexb/python-publicsuffix2
COMMENT=	Public suffix for a domain name using the Public Suffix List
LICENSE=	mit AND mpl-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
