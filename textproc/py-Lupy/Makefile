# $NetBSD: Makefile,v 1.4 2004/07/22 09:16:01 recht Exp $
#

DISTNAME=		Lupy-0.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lupy/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://divmod.org/Lupy/index.html
COMMENT=		Full-text indexer and search engine

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
