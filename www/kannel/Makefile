# $NetBSD: Makefile,v 1.10 2002/08/01 05:48:24 jlam Exp $
#

DISTNAME=	gateway-${KANNEL_VER}
PKGNAME=	kannel-${KANNEL_VER}
CATEGORIES=	www net
MASTER_SITES=	http://www.kannel.3glab.org/download/${KANNEL_VER}/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kannel.org/
COMMENT=	open source WAP and SMS gateway

KANNEL_VER=	1.0.3

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_PERL5=		YES
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
