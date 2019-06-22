# $NetBSD: Makefile,v 1.15 2019/06/22 11:37:13 nia Exp $

DISTNAME=		luit-20190106
# check if this line needs changes when packaging newer snapshots
PKGNAME=		${DISTNAME:S/-2/-2.0.2/}
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.invisible-island.net/luit/
EXTRACT_SUFX=		.tgz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://invisible-island.net/luit/
COMMENT=		Locale and ISO 2022 support for Unicode terminals
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
