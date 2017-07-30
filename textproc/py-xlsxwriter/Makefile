# $NetBSD: Makefile,v 1.11 2017/07/30 22:32:24 wiz Exp $

DISTNAME=	XlsxWriter-0.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmcnamara/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jmcnamara/XlsxWriter/
COMMENT=	Python module for creating Excel XLSX files
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	XlsxWriter
GITHUB_TAG=	RELEASE_${PKGVERSION_NOREV}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
