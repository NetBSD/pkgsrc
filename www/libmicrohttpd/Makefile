# $NetBSD: Makefile,v 1.18 2014/01/01 11:52:02 wiz Exp $

DISTNAME=	libmicrohttpd-0.9.32
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=libmicrohttpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libmicrohttpd/
COMMENT=	Small C library to run an HTTP server as part of another app
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
# Too many problems with libmicrospdy at the moment (0.9.31)
CONFIGURE_ARGS+=	--disable-spdy
# Avoid building and installing 'demo' program
CONFIGURE_ENV+=		ac_cv_header_magic_h=no
INFO_FILES=		yes

PKGCONFIG_OVERRIDE+=	libmicrohttpd.pc.in

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
