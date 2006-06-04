# $NetBSD: Makefile,v 1.10 2006/06/04 12:00:58 joerg Exp $
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

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
