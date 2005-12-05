# $NetBSD: Makefile,v 1.12 2005/12/05 20:51:07 rillig Exp $

DISTNAME=	HappyDoc_r2_1
PKGNAME=	${PYPKGPREFIX}-HappyDoc-2.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=happydoc/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://happydoc.sf.net/
COMMENT=	Python tool to generate Python API documents

WRKSRC=		${WRKDIR}/HappyDoc-r2_1
PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	${MV} ${WRKSRC}/happydoc ${WRKSRC}/happydoc${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
