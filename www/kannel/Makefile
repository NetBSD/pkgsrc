# $NetBSD: Makefile,v 1.8.2.2 2002/07/01 17:45:14 jlam Exp $
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
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_PTHREAD=		native pth

CONFIGURE_ARGS+=	--disable-docs
CFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2/libxml

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
