# $NetBSD: Makefile,v 1.6 2005/04/11 21:47:41 tv Exp $
#

DISTNAME=		Lupy-0.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lupy/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://divmod.org/Lupy/index.html
COMMENT=		Full-text indexer and search engine

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
