# $NetBSD: Makefile,v 1.11 2002/08/22 11:31:33 martti Exp $
#

DISTNAME=	gateway-${KANNEL_VER}
PKGNAME=	kannel-${KANNEL_VER}
CATEGORIES=	www net
MASTER_SITES=	http://www.kannel.org/download/${KANNEL_VER}/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kannel.org
COMMENT=	Open source WAP and SMS gateway

KANNEL_VER=	1.2.0

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_PERL5=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--disable-docs
CONFIGURE_ARGS+=	--disable-ssl

.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
