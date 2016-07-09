# $NetBSD: Makefile,v 1.9 2016/07/09 13:04:13 wiz Exp $

DISTNAME=	ClientForm-0.2.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	http://wwwsearch.sourceforge.net/ClientForm/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwsearch.sourceforge.net/ClientForm/
COMMENT=	Python module for handling HTML forms on the client side
LICENSE=	modified-bsd OR zpl-2.0

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.2.10

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
