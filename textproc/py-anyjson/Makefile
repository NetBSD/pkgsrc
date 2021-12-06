# $NetBSD: Makefile,v 1.6 2021/12/06 14:59:35 wiz Exp $

DISTNAME=	anyjson-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
