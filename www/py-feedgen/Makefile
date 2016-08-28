# $NetBSD: Makefile,v 1.2 2016/08/28 15:48:36 wiz Exp $

DISTNAME=	v0.3.2
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT:S/python-//}-${DISTNAME:S/v//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=lkiesow/}
GITHUB_PROJECT=	python-feedgen
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=lkiesow/python-feedgen/}
COMMENT=	Python module to generate ATOM feeds, RSS feeds, and Podcasts
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
