# $NetBSD: Makefile,v 1.9 2006/03/04 21:30:51 jlam Exp $
#

DISTNAME=		Lupy-0.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lupy/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://divmod.org/Lupy/index.html
COMMENT=		Full-text indexer and search engine

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
