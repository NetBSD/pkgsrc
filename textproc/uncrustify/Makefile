# $NetBSD: Makefile,v 1.15 2023/07/11 05:58:40 nia Exp $

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

# gcc 4.9 added support for std::regex_replace.
GCC_REQD+=	4.9

OBJDIR=			${WRKSRC}/build
CONFIGURE_DIRS=		${OBJDIR}
CMAKE_ARG_PATH=		${WRKSRC}

PYTHON_FOR_BUILD_ONLY=		tool

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
