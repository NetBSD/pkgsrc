# $NetBSD: Makefile,v 1.21 2012/02/04 11:48:08 obache Exp $

DISTNAME=	HappyDoc_r2_1
PKGNAME=	${PYPKGPREFIX}-HappyDoc-2.1
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=happydoc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://happydoc.sourceforge.net/
COMMENT=	Python tool to generate Python API documents

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	#none

WRKSRC=		${WRKDIR}/HappyDoc-r2_1
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}
EGG_NAME=	${DISTNAME:S/_r/-/:S/_/./g}

post-extract:
	${MV} ${WRKSRC}/happydoc ${WRKSRC}/happydoc${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
