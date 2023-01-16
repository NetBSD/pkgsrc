# $NetBSD: Makefile,v 1.12 2023/01/16 01:15:44 dholland Exp $

DISTNAME=	uncrustify-0.72.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=uncrustify/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://uncrustify.sourceforge.net/
COMMENT=	Source Code Beautifier for C-like languages
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

OBJDIR=			${WRKSRC}/build
CONFIGURE_DIRS=		${OBJDIR}
CMAKE_ARG_PATH=		${WRKSRC}

PYTHON_FOR_BUILD_ONLY=		tool

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
