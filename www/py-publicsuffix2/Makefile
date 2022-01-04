# $NetBSD: Makefile,v 1.4 2022/01/04 20:55:33 wiz Exp $

DISTNAME=	publicsuffix2-2.20190812
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
