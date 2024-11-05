# $NetBSD: Makefile,v 1.11 2024/11/05 17:20:04 adam Exp $

DISTNAME=	sord-0.16.16
CATEGORIES=	textproc
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/sord/
COMMENT=	Lightweight C library for storing RDF data in memory
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/sord-0.pc

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zix/buildlink3.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.30.0
.include "../../textproc/serd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
