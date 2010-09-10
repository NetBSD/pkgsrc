# $NetBSD: Makefile,v 1.6 2010/09/10 19:15:54 joerg Exp $
#

DISTNAME=		luit-1.0.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Locale and ISO 2022 support for Unicode terminals
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
