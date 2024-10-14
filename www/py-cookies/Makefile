# $NetBSD: Makefile,v 1.5 2024/10/14 08:16:22 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	311 312 313

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
