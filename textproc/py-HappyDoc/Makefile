# $NetBSD: Makefile,v 1.1.1.1 2002/01/29 16:26:44 drochner Exp $

DISTNAME=	HappyDoc_r2_0
PKGNAME=	${PYPKGPREFIX}-HappyDoc-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=happydoc/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://happydoc.sf.net/
COMMENT=	python tool to generate Python API documents

PYTHON_VERSIONS_ACCEPTED=	21
PYDISTUTILSPKG=	# defined
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

WRKSRC=		${WRKDIR}/HappyDoc-r2_0

post-extract:
	${MV} ${WRKSRC}/happydoc ${WRKSRC}/happydoc${PYVERSSUFFIX}

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
