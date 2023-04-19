# $NetBSD: Makefile,v 1.52 2023/04/19 08:11:47 adam Exp $

DISTNAME=	gateway-${KANNEL_VER}
PKGNAME=	kannel-${KANNEL_VER}
PKGREVISION=	20
CATEGORIES=	www net
MASTER_SITES=	https://www.kannel.org/download/${KANNEL_VER}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kannel.org/
COMMENT=	Open source WAP and SMS gateway

KANNEL_VER=	1.4.0

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl:run
PTHREAD_OPTS+=		require

CONFIGURE_ARGS+=	--disable-docs
CONFIGURE_ARGS+=	--disable-ssl
CFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2/libxml

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
