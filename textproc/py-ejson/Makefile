# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:54 wiz Exp $

DISTNAME=	ejson-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ejson/}
DIST_SUBDIR=	${PKGBASE:S/${PYPKGPREFIX}/py/1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yipit/ejson/
COMMENT=	Extensible JSON serializers and deserializers
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
