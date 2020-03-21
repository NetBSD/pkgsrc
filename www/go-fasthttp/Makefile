# $NetBSD: Makefile,v 1.5 2020/03/21 16:57:02 bsiegert Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-fasthttp-1.6.0
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=valyala/}
GITHUB_PROJECT=		fasthttp

MAINTAINER=		ng0@NetBSD.org
HOMEPAGE=		https://github.com/valyala/fasthttp/
COMMENT=		Fast HTTP package for Go
LICENSE=		mit

GO_SRCPATH=		github.com/valyala/fasthttp
GO_DIST_BASE=		fasthttp-${PKGVERSION_NOREV}

# This is an sh script, no Bash syntax found.
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-build
SUBST_FILES.bash=	${WRKDIR}/src/github.com/valyala/fasthttp/fuzzit.sh
SUBST_SED.bash=		-e "s,bash,sh,g"

.include "../../devel/go-bytebufferpool/buildlink3.mk"
.include "../../net/go-tcplisten/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../devel/go-cpuid/buildlink3.mk"
.include "../../devel/go-compress/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
