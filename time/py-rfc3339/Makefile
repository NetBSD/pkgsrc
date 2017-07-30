# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:25 wiz Exp $

DISTNAME=	pyRFC3339-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=kurtraschke/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kurtraschke/pyRFC3339/
COMMENT=	Library for generating and parsing RFC 3339-compliant timestamps
LICENSE=	mit

GITHUB_PROJECT=	pyRFC3339
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
