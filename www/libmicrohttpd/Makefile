# $NetBSD: Makefile,v 1.29 2017/01/01 16:06:38 adam Exp $

DISTNAME=	libmicrohttpd-0.9.52
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
INFO_FILES=		yes

PKGCONFIG_OVERRIDE+=	libmicrohttpd.pc.in

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
