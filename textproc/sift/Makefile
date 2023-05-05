# $NetBSD: Makefile,v 1.63 2023/05/05 19:37:34 bsiegert Exp $

DISTNAME=	sift-0.9.0
PKGREVISION=	9
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
