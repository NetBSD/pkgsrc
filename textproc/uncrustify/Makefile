# $NetBSD: Makefile,v 1.14 2023/04/05 09:08:11 nikita Exp $

DISTNAME=	uncrustify-0.76.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=uncrustify/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://uncrustify.sourceforge.net/
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
