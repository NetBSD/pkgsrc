# $NetBSD: Makefile,v 1.1.1.1 2010/05/01 20:45:05 wiz Exp $
#

DISTNAME=	Whoosh-0.1.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc devel
MASTER_SITES=	http://pypi.python.org/packages/source/W/Whoosh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://whoosh.ca/
COMMENT=	Fast, featureful full-text indexing and searching library implemented
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none
PYTHON_VERSIONS_INCOMPATIBLE=	24
PYDISTUTILSPKG=		yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
