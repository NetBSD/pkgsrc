# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:40 jmmv Exp $

DISTNAME=	HappyDoc_r2_1
PKGNAME=	${PYPKGPREFIX}-HappyDoc-2.1
WRKSRC=		${WRKDIR}/HappyDoc-r2_1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=happydoc/}

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://happydoc.sf.net/
COMMENT=	python tool to generate Python API documents

PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/happydoc ${WRKSRC}/happydoc${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
