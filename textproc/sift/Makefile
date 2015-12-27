# $NetBSD: Makefile,v 1.1 2015/12/27 20:50:40 wiz Exp $

DISTNAME=	sift-0.6.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=svent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sift-tool.org/
COMMENT=	Fast and powerful open source alternative to grep
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	go-crypto-[0-9]*:../../security/go-crypto
BUILD_DEPENDS+=	go-nbreader-[0-9]*:../../devel/go-nbreader
BUILD_DEPENDS+=	go-flags-svent-[0-9]*:../../devel/go-flags-svent

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/svent/sift

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
