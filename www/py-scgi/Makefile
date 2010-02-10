# $NetBSD: Makefile,v 1.5 2010/02/10 21:10:25 joerg Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

COMMENT=	Simple Common Gateway Interface

PKG_DESTDIR_SUPPORT=	destdir

DEPENDS+=	${PYPKGPREFIX}-quixote-[0-9]*:../../devel/py-quixote

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
.include "../../lang/python/extension.mk"

.include "../../www/py-scgi/Makefile.common"
