# $NetBSD: Makefile,v 1.8 2015/12/05 21:26:02 adam Exp $
#

DISTNAME=	Whoosh-2.5.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc devel
MASTER_SITES=	http://pypi.python.org/packages/source/W/Whoosh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://whoosh.ca/
COMMENT=	Fast, featureful full-text indexing and searching library implemented
LICENSE=	apache-2.0

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
