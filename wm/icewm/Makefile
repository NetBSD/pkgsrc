# $NetBSD: Makefile,v 1.58 2024/06/13 21:17:39 gutteridge Exp $

DISTNAME=	icewm-3.5.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=ice-wm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ice-wm.org/
COMMENT=	Small, fast and light-weight window manager
LICENSE=	gnu-gpl-v2

FILESDIR=	${.CURDIR}/../../wm/icewm/files

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		MARKDOWN=multimarkdown

CONFIGURE_ARGS+=	--enable-corefonts
CONFIGURE_ARGS+=	--enable-i18n

TOOL_DEPENDS+=	multimarkdown-[0-9]*:../../textproc/multimarkdown

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake perl autoreconf autoconf automake autopoint

REPLACE_PERL=	contrib/icewm-menu-xrandr

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoreconf -fis

post-extract:
	cp ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/taskbar

.include "options.mk"

.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
