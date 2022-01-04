# $NetBSD: Makefile,v 1.7 2022/01/04 20:54:52 wiz Exp $

DISTNAME=	anyjson-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anyjson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/runeh/anyjson/
COMMENT=	Wraps the JSON implementation available in a common interface
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

.if ${PYPKGPREFIX} != "py27"
post-extract:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs anyjson
.endif

.include "../../mk/bsd.pkg.mk"
