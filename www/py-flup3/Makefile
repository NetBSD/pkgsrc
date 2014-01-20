# $NetBSD: Makefile,v 1.2 2014/01/20 11:10:04 wiz Exp $

DISTNAME=	cc23b715b120
PKGNAME=	${PYPKGPREFIX}-flup-1.0.3pre1
CATEGORIES=	www python
MASTER_SITES=	http://hg.saddi.com/flup-py3.0/archive/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://hg.saddi.com/flup-py3.0/
COMMENT=	WSGI support modules (python-3.x version)
LICENSE=	2-clause-bsd

DIST_SUBDIR=	py-flup
EGG_NAME=	flup-1.0.3.dev
WRKSRC=		${WRKDIR}/flup-py3-0-${DISTNAME}

USE_LANGUAGES=	# empty
PYTHON_VERSIONS_INCOMPATIBLE=	26 27
PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
