# $NetBSD: Makefile,v 1.6 2010/06/13 22:45:53 wiz Exp $

DISTNAME=		tint2-0.9
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://tint2.googlecode.com/files/

MAINTAINER=		fernandotcl@gmail.com
HOMEPAGE=		http://code.google.com/p/tint2/
COMMENT=		Tint2 is a simple panel/taskbar
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKG_SYSCONFSUBDIR=	xdg
INSTALLATION_DIRS=	share/examples/tint2
OWN_DIRS=		${PKG_SYSCONFDIR}/tint2
CONF_FILES=		${PREFIX}/share/examples/tint2/tint2rc \
				${PKG_SYSCONFDIR}/tint2/tint2rc

CONFIGURE_ARGS+=	--disable-tint2conf
CONFIGURE_ARGS+=	--disable-examples
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-battery
.else
CONFIGURE_ARGS+=	--disable-battery
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample/tint2rc \
		${DESTDIR}${PREFIX}/share/examples/tint2

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
