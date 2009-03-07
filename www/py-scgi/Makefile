# $NetBSD: Makefile,v 1.3 2009/03/07 16:26:16 tnn Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface

PKG_DESTDIR_SUPPORT=	destdir

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
.include "../../lang/python/extension.mk"

.include "../../www/py-scgi/Makefile.common"
