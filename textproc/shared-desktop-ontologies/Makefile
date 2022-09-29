# $NetBSD: Makefile,v 1.11 2022/09/29 05:47:18 markd Exp $

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

PKGCONFIG_OVERRIDE+=	shared-desktop-ontologies.pc.cmake

.include "../../mk/bsd.pkg.mk"
