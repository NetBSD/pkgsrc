# $NetBSD: Makefile,v 1.34 2020/03/20 11:58:28 nia Exp $

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
EGG_NAME=	${DISTNAME:S/_r/-/:S/_/./g}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.1

post-extract:
	${MV} ${WRKSRC}/happydoc ${WRKSRC}/happydoc${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
