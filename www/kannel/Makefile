# $NetBSD: Makefile,v 1.8.2.1 2002/06/23 19:03:58 jlam Exp $
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
USE_PTHREAD=		native pth

CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
