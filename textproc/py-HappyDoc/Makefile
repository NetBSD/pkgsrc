# $NetBSD: Makefile,v 1.17 2008/04/25 20:39:12 joerg Exp $

DISTNAME=	HappyDoc_r2_1
PKGNAME=	${PYPKGPREFIX}-HappyDoc-2.1
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=happydoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://happydoc.sourceforge.net/
COMMENT=	Python tool to generate Python API documents

WRKSRC=		${WRKDIR}/HappyDoc-r2_1
PYDISTUTILSPKG=	# defined
PYTHON_VERSIONS_ACCEPTED=	25 24 23 21
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	${MV} ${WRKSRC}/happydoc ${WRKSRC}/happydoc${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
