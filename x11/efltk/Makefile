# $NetBSD: Makefile,v 1.37 2020/03/20 11:58:36 nia Exp $
#

DISTNAME=	efltk-2.0.5
PKGREVISION=	22
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ede.sourceforge.net/
COMMENT=	Extended Fast Light Toolkit
LICENSE=	gnu-lgpl-v2 # or later

WRKSRC=			${WRKDIR}/efltk
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++03
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--enable-iconv
CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--disable-unixODBC
CONFIGURE_ARGS+=	--disable-shared

INSTALL_MAKE_FLAGS+=	INSTALL_PREFIX=${DESTDIR:Q}

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
