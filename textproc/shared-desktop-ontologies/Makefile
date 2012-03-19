# $NetBSD: Makefile,v 1.3 2012/03/19 08:53:30 markd Exp $

DISTNAME=	shared-desktop-ontologies-0.7.0
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
