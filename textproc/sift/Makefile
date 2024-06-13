# $NetBSD: Makefile,v 1.75 2024/06/13 13:47:11 bsiegert Exp $

DISTNAME=	sift-0.9.0
PKGREVISION=	21
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
