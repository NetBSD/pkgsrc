# $NetBSD: Makefile,v 1.26 2016/07/09 13:04:09 wiz Exp $

DISTNAME=	HappyDoc_r2_1
PKGNAME=	${PYPKGPREFIX}-HappyDoc-2.1
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=happydoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://happydoc.sourceforge.net/
COMMENT=	Python tool to generate Python API documents

USE_LANGUAGES=	#none

WRKSRC=		${WRKDIR}/HappyDoc-r2_1
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
EGG_NAME=	${DISTNAME:S/_r/-/:S/_/./g}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 2.1

post-extract:
	${MV} ${WRKSRC}/happydoc ${WRKSRC}/happydoc${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
