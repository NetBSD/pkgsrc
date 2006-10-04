# $NetBSD: Makefile,v 1.11 2006/10/04 22:01:00 wiz Exp $
#

DISTNAME=		Lupy-0.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lupy/}

MAINTAINER=		pkgsrc-users@NetBSD.org
# "The Lupy project has been RETIRED!"
HOMEPAGE=		http://divmod.org/trac/wiki/WhitherLupy
COMMENT=		Full-text indexer and search engine

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	24 23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
