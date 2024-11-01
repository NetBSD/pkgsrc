# $NetBSD: Makefile,v 1.34 2024/11/01 00:54:05 wiz Exp $
#

DISTNAME=	libmrss-0.19.2
PKGREVISION=	31
CATEGORIES=	www
MASTER_SITES=	https://www.autistici.org/bakunin/libmrss/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.autistici.org/bakunin/libmrss/
COMMENT=	C library for parsing, writing and creating RSS files or streams
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	mrss.pc.in

.include "../../textproc/libnxml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
