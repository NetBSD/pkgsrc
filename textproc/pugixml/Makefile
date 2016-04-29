# $NetBSD: Makefile,v 1.1 2016/04/29 11:54:54 wiz Exp $

DISTNAME=	pugixml-1.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeux/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pugixml.org/
COMMENT=	Light-weight C++ XML processing library
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_CMAKE=	yes
CMAKE_ARG_PATH=	scripts

.include "../../mk/bsd.pkg.mk"
