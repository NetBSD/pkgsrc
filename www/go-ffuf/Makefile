# $NetBSD: Makefile,v 1.4 2020/08/14 20:01:20 bsiegert Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-fuff-1.0.2
PKGREVISION=		3
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=ffuf/}
GITHUB_PROJECT=		ffuf

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://github.com/ffuf/ffuf/
COMMENT=		Fast web fuzzer
LICENSE=		mit

GO_SRCPATH=		github.com/ffuf/ffuf
GO_DIST_BASE=		ffuf-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
