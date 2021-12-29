# $NetBSD: Makefile,v 1.66 2021/12/29 08:34:52 nikita Exp $

DISTNAME=	libmicrohttpd-0.9.75
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=libmicrohttpd/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libmicrohttpd/
COMMENT=	Small C library to run an HTTP server as part of another app
LICENSE=	gnu-lgpl-v2.1 # or later

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
INFO_FILES=		yes
# 2 tests skipped as of 0.9.75, this is expected.
# SKIP: test_https_get_parallel_threads
# SKIP: test_https_session_info
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	libmicrohttpd.pc.in
CONFIGURE_ARGS+=	--enable-https

.include "../../security/gnutls/buildlink3.mk"
# This is actually only needed for tests, but linked
BUILDLINK_DEPMETHOD.curl=	build
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
