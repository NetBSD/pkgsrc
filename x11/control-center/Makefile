# $NetBSD: Makefile,v 1.2 2005/06/17 04:49:49 jlam Exp $

DISTNAME=		control-center-1.4.0.4
PKGREVISION=		10
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/control-center/1.4/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME control-center development library

BUILD_USES_MSGFMT=	YES

USE_DIRS+=		xdg-1.1
USE_X11BASE=		YES
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES

USE_LIBTOOL=		YES

LOCALSTATEDIR=		${PREFIX}/var

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR}

.include "../../mk/bsd.prefs.mk"

# Linux has libintl functionality in libc
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		INTLLIBS="-lintl"
.endif

post-patch:
	@${ECHO} >>${WRKSRC}/control-center/cappletConf.sh.in ""

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/control-center/capplets

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
