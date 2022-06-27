# $NetBSD: Makefile,v 1.2 2022/06/27 15:29:17 fcambus Exp $

DISTNAME=	ydiff-1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ymattw/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ymattw/ydiff
COMMENT=	Inline and side-by-side colored and incremental diff viewer
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
