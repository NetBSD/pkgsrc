# $NetBSD: Makefile,v 1.17 2020/06/17 09:54:18 bsiegert Exp $

DISTNAME=	webhooks-3.12.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-playground/}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/go-playground/webhooks
COMMENT=	Webhook receiver for GitHub, Bitbucket, and GitLab
LICENSE=	mit

SUBST_CLASSES+=		import
SUBST_STAGE.import=	pre-configure
SUBST_MESSAGE.import=	Fixing import paths for go-gogs-client.
SUBST_FILES.import=	gogs/gogs.go
SUBST_SED.import=	-e 's,/gogits/,/gogs/,g'

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	gopkg.in/go-playground/webhooks.v3

.include "../../www/go-gogs-client/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
