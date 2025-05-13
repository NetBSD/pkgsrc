# $NetBSD: Makefile,v 1.1 2025/05/13 03:54:02 schmonz Exp $

DISTNAME=		apaste-0.0.3.0
CATEGORIES=		www
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/apaste/
COMMENT=		Small command-line pastebin to share terminal output
LICENSE=		isc

DEPENDS+=		s6-networking-[0-9]*:../../net/s6-networking

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig

# for mkdtemp
CPPFLAGS.Darwin+=	-D_DARWIN_C_SOURCE

.include "../../devel/skalibs/buildlink3.mk"
.include "../../net/s6-networking/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
