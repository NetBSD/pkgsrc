# $NetBSD: Makefile,v 1.3 2019/05/14 12:54:17 ryoon Exp $

DISTNAME=	uncrustify-uncrustify-0.69.0
PKGNAME=	${DISTNAME:S/uncrustify-//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=uncrustify/}
GITHUB_PROJECT=	uncrustify
GITHUB_TAG=	uncrustify-0.69.0

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://uncrustify.sourceforge.net/
COMMENT=	Source Code Beautifier for C-like languages
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

OBJDIR=			${WRKSRC}/build
CONFIGURE_DIRS=		${OBJDIR}
CMAKE_ARG_PATH=		${WRKSRC}

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../mk/bsd.pkg.mk"
