# $NetBSD: Makefile,v 1.1 2026/11/27 11:49:31 adam Exp $

DISTNAME=	katana-1.8.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/katana
COMMENT=	Crawling and spidering framework
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/katana

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
