# $NetBSD: Makefile,v 1.1 2026/11/15 21:15:36 wiz Exp $

DISTNAME=	owlrl-7.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/owlrl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RDFLib/OWL-RL
COMMENT=	Simple implementation of the OWL2 RL Profile
LICENSE=	w3c

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry>=0:../../devel/py-poetry
DEPENDS+=	${PYPKGPREFIX}-rdflib>=7.3.0:../../textproc/py-rdflib

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
