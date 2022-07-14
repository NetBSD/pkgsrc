# $NetBSD: Makefile,v 1.99 2022/07/14 23:46:27 dholland Exp $

DISTNAME=	netsurf-all-3.10
PKGNAME=	${DISTNAME:S/-all//}
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	https://download.netsurf-browser.org/netsurf/releases/source-full/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netsurf-browser.org/
COMMENT=	Web browser for RISC OS and UNIX-like platforms
LICENSE=	gnu-gpl-v2 AND mit

BUILD_DEPENDS+=	lemon>=1.0:../../devel/lemon
BUILD_DEPENDS+=	re2c>=0.12:../../devel/re2c
BUILD_DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

BUILD_TARGET=	build
USE_TOOLS+=	bison flex gmake perl:build pax pkg-config

MAKE_FLAGS+=	TARGET=gtk3

SUBST_CLASSES+=			ssl-certs
SUBST_STAGE.ssl-certs=		pre-configure
SUBST_MESSAGE.ssl-certs=	Fixing hardcoded paths for SSL certs
SUBST_FILES.ssl-certs=		netsurf/frontends/beos/gui.cpp
SUBST_FILES.ssl-certs+=		netsurf/test/data/Choices
SUBST_FILES.ssl-certs+=		netsurf/test/data/Choices-all
SUBST_FILES.ssl-certs+=		netsurf/test/data/Choices-full
SUBST_FILES.ssl-certs+=		netsurf/test/data/Choices-short
SUBST_SED.ssl-certs=		-e 's,/etc/ssl/certs,${SSLCERTS},'

# Avoid possible problems with already often defined HOST
MAKE_ENV+=	BUILD="${MACHINE_GNU_ARCH}--${LOWER_OPSYS}"
MAKE_ENV+=	HOST="${MACHINE_GNU_ARCH}--${LOWER_OPSYS}"

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/netsurf
INSTALLATION_DIRS+=	share/pixmaps

BUILDLINK_TRANSFORM+=	rm:-Werror
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE	# needed for strcasestr(3) and strndup(3)

# Needed for the xxd utility
TOOL_DEPENDS+=		vim-share-[0-9]*:../../editors/vim-share

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	pre-install
SUBST_MESSAGE.bin=	Changing executable name in .desktop file
SUBST_FILES.bin=	netsurf/frontends/gtk/res/netsurf-gtk.desktop
SUBST_SED.bin=		-e 's,netsurf-gtk,netsurf-gtk3,g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/netsurf/frontends/gtk/res/netsurf.xpm \
		${DESTDIR}${PREFIX}/share/pixmaps/netsurf.xpm
	${INSTALL_DATA} ${WRKSRC}/netsurf/frontends/gtk/res/netsurf-gtk.desktop \
		${DESTDIR}${PREFIX}/share/applications/netsurf-gtk.desktop

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
