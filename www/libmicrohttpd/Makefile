# $NetBSD: Makefile,v 1.57 2020/08/09 15:27:47 nia Exp $

DISTNAME=	libmicrohttpd-0.9.71
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=libmicrohttpd/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libmicrohttpd/
COMMENT=	Small C library to run an HTTP server as part of another app
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gettext
GNU_CONFIGURE=		yes
INFO_FILES=		yes
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	libmicrohttpd.pc.in
CONFIGURE_ARGS+=	--enable-nls

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
