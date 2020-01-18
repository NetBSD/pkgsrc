# $NetBSD: Makefile,v 1.8 2020/01/18 23:35:33 rillig Exp $

DISTNAME=	shared-desktop-ontologies-0.11.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oscaf/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://oscaf.sourceforge.net/
COMMENT=	Ontologies for Semantic Desktop
#LICENSE=	modified-bsd

# BUILD_MAKE_FLAGS+= VERBOSE=1

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	shared-desktop-ontologies.pc.cmake

.include "../../mk/bsd.pkg.mk"
