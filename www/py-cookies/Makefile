# $NetBSD: Makefile,v 1.4 2023/11/05 20:21:52 wiz Exp $

DISTNAME=	cookies-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cookies/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sashahart/cookies
COMMENT=	RFC 6265-compliant cookie parser/renderer
LICENSE=	mit

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 312

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
