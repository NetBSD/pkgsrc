# $NetBSD: Makefile,v 1.6 2017/09/04 18:08:30 wiz Exp $

DISTNAME=	cc23b715b120
PKGNAME=	${PYPKGPREFIX}-flup-1.0.3pre1
CATEGORIES=	www python
MASTER_SITES=	https://hg.saddi.com/flup-py3.0/archive/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://hg.saddi.com/flup-py3.0/
COMMENT=	WSGI support modules (python-3.x version)
LICENSE=	2-clause-bsd

DIST_SUBDIR=	py-flup
EGG_NAME=	flup-1.0.3.dev0
WRKSRC=		${WRKDIR}/flup-py3-0-${DISTNAME}

USE_LANGUAGES=	# empty
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
