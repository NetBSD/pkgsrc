# $NetBSD: Makefile,v 1.16 2003/05/05 19:05:22 jmmv Exp $
#

DISTNAME=	gateway-${KANNEL_VER}
PKGNAME=	kannel-${KANNEL_VER}
PKGREVISION=	1
CATEGORIES=	www net
MASTER_SITES=	http://www.kannel.org/download/${KANNEL_VER}/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kannel.org
COMMENT=	Open source WAP and SMS gateway

KANNEL_VER=	1.2.1

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--disable-docs
CONFIGURE_ARGS+=	--disable-ssl
CFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2/libxml

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
