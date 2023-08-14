# $NetBSD: Makefile,v 1.4 2023/08/14 05:25:25 wiz Exp $

DISTNAME=	ydiff-1.2
PKGREVISION=	2
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
