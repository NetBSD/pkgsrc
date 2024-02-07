# $NetBSD: Makefile,v 1.72 2024/02/07 14:51:02 bsiegert Exp $

DISTNAME=	sift-0.9.0
PKGREVISION=	18
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=svent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sift-tool.org/
COMMENT=	Fast and powerful open source alternative to grep
LICENSE=	gnu-gpl-v3

post-extract:
	${CP} files/go.mod files/go.sum ${WRKSRC}/

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
