# $NetBSD: Makefile,v 1.95 2018/08/22 09:47:26 wiz Exp $

DISTNAME=	w3c-libwww-5.4.2
PKGNAME=	${DISTNAME:S/^w3c-//}
PKGREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.w3.org/Library/
COMMENT=	The W3C Reference Library
LICENSE=	w3c

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gzcat perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-ssl #=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--without-x

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
# IRIX 5 does not have libregex
CONFIGURE_ARGS+=	--with-regex
.endif

.if !exists(/usr/include/md5.h)
CONFIGURE_ARGS+=	--with-md5=${SSLBASE:Q}
.endif

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
