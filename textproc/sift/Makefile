# $NetBSD: Makefile,v 1.26 2020/03/21 16:57:19 bsiegert Exp $

DISTNAME=	sift-0.6.0
PKGREVISION=	24
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=svent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sift-tool.org/
COMMENT=	Fast and powerful open source alternative to grep
LICENSE=	gnu-gpl-v3

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/svent/sift

post-install:
	find ${DESTDIR}${PREFIX}/gopkg/src/${GO_SRCPATH} -name "*.orig" -exec ${RM} \{\} \;

.include "../../security/go-crypto/buildlink3.mk"
.include "../../devel/go-nbreader/buildlink3.mk"
.include "../../devel/go-flags-svent/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
