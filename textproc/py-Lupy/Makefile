# $NetBSD: Makefile,v 1.3 2004/05/18 12:44:05 recht Exp $
#

DISTNAME=		Lupy-0.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc
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
