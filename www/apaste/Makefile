# $NetBSD: Makefile,v 1.2 2025/07/08 21:19:54 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		apaste-0.0.3.0
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=skarnet/}
GITHUB_PROJECT=		apaste
GITHUB_TAG=		4813dd0cc1b8f408c8a46299acdc666e0e03831e

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/apaste/
COMMENT=		Small command-line pastebin to share terminal output
LICENSE=		isc

DEPENDS+=		s6-networking-[0-9]*:../../net/s6-networking

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-allstatic

# for mkdtemp
CPPFLAGS.Darwin+=	-D_DARWIN_C_SOURCE

.include "../../devel/skalibs/buildlink3.mk"
.include "../../net/s6-networking/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
