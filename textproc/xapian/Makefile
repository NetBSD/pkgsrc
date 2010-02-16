# $NetBSD: Makefile,v 1.11 2010/02/16 14:51:26 wiz Exp $
#

DISTNAME=	xapian-core-1.0.18
PKGNAME=	${DISTNAME:S/-core//}
CATEGORIES=	textproc
MASTER_SITES=	http://oligarchy.co.uk/xapian/1.0.18/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://xapian.org/
COMMENT=	Search engine based on Probabilistic Information Retrieval
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	check

PKG_OPTIONS_VAR=	PKG_OPTIONS.xapian
PKG_SUPPORTED_OPTIONS=	xapian-flint-backend xapian-quartz-backend
PKG_SUGGESTED_OPTIONS=	xapian-flint-backend xapian-quartz-backend

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		quartz
.if !empty(PKG_OPTIONS:Mxapian-quartz-backend)
CONFIGURE_ARGS+=	--enable-backend-quartz
PLIST.quartz=		yes
.else
CONFIGURE_ARGS+=	--disable-backend-quartz
.endif

PLIST_VARS+=		flint
.if !empty(PKG_OPTIONS:Mxapian-flint-backend)
CONFIGURE_ARGS+=	--enable-backend-flint
PLIST.flint=		yes
.else
CONFIGURE_ARGS+=	--disable-backend-flint
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
