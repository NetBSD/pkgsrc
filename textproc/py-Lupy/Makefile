# $NetBSD: Makefile,v 1.1.1.1 2003/12/06 19:39:48 recht Exp $
#

DISTNAME=		Lupy-0.1.5.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/lupy/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://divmod.org/Lupy/index.html
COMMENT=		Full-text indexer and search engine

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 22 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
