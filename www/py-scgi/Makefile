# $NetBSD: Makefile,v 1.2 2009/03/03 10:53:15 manu Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface

PKG_DESTDIR_SUPPORT=	destdir

DEPENDS+=	${PYPKGPREFIX}-quixote:../../devel/py-quixote

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
.include "../../lang/python/extension.mk"

.include "../../www/py-scgi/Makefile.common"
