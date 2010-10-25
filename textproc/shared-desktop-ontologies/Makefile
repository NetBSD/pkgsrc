# $NetBSD: Makefile,v 1.2 2010/10/25 20:14:49 markd Exp $

DISTNAME=	shared-desktop-ontologies-0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oscaf/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://oscaf.sourceforge.net
COMMENT=	Ontologies for Semantic Desktop
#LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	shared-desktop-ontologies.pc.cmake

.include "../../mk/bsd.pkg.mk"
