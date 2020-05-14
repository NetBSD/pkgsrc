# $NetBSD: Makefile,v 1.1 2020/05/14 10:36:50 nikita Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-fuff-1.0.2
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
