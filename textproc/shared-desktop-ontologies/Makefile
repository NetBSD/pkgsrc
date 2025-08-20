# $NetBSD: Makefile,v 1.12 2025/08/20 11:35:13 wiz Exp $

DISTNAME=	shared-desktop-ontologies-0.11.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oscaf/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://oscaf.sourceforge.net/
COMMENT=	Ontologies for Semantic Desktop
#LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	# none

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	shared-desktop-ontologies.pc.cmake

.include "../../mk/bsd.pkg.mk"
