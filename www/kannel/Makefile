# $NetBSD: Makefile,v 1.22 2004/01/24 15:23:47 grant Exp $
#

DISTNAME=	gateway-${KANNEL_VER}
PKGNAME=	kannel-${KANNEL_VER}
PKGREVISION=	4
CATEGORIES=	www net
MASTER_SITES=	http://www.kannel.org/download/${KANNEL_VER}/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.kannel.org/
COMMENT=	Open source WAP and SMS gateway

KANNEL_VER=	1.2.1

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--disable-docs
CONFIGURE_ARGS+=	--disable-ssl
CFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2/libxml

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
