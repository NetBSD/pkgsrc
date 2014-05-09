# $NetBSD: Makefile,v 1.6 2014/05/09 07:37:21 wiz Exp $
#

DISTNAME=	Whoosh-0.1.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc devel
MASTER_SITES=	http://pypi.python.org/packages/source/W/Whoosh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://whoosh.ca/
COMMENT=	Fast, featureful full-text indexing and searching library implemented
LICENSE=	apache-2.0

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
