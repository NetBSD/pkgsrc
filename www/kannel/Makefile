# $NetBSD: Makefile,v 1.23 2004/04/27 05:44:23 snj Exp $
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
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--disable-docs
CONFIGURE_ARGS+=	--disable-ssl
CFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2/libxml

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
