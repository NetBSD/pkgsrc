# $NetBSD: Makefile,v 1.159 2024/05/29 16:35:17 adam Exp $

DISTNAME=		xscreensaver-6.08
PKGREVISION=		5
CATEGORIES=		x11
MASTER_SITES=		https://www.jwz.org/xscreensaver/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Screen saver and locker for the X window system
HOMEPAGE=		https://www.jwz.org/xscreensaver/

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_CC_FEATURES=	c99
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config

CHECK_PORTABILITY_SKIP+=	OSX/fuzztest.sh
CHECK_PORTABILITY_SKIP+=	OSX/installer.sh
CHECK_PORTABILITY_SKIP+=	android/Makefile

CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config
CONFIGURE_ARGS+=	--with-gl
CONFIGURE_ARGS+=	--with-gle
CONFIGURE_ARGS+=	--with-gtk=${BUILDLINK_PREFIX.gtk3}
CONFIGURE_ARGS+=	--with-hackdir=${PREFIX}/libexec/xscreensaver
CONFIGURE_ARGS+=	--with-jpeg=${JPEGBASE}
CONFIGURE_ARGS+=	--without-motif

CONFIGURE_ARGS.NetBSD+=	--without-kerberos

CONFIGURE_ENV+=		ac_cv_x_app_defaults="${PREFIX}/lib/X11/app-defaults"

CONFLICTS+=	xscreensaver-gnome<4.14 xscreensaver-demo-[0-9]*

.include "../../mk/compiler.mk"
.if ${CC_VERSION:Mgcc*}
CFLAGS+=		-fno-strict-aliasing
.endif

.if !exists(/usr/bin/bc)
TOOL_DEPENDS+=		bc-[0-9]*:../../math/bc
.endif

INSTALL_MAKE_FLAGS=	install_prefix=${DESTDIR}

INSTALLATION_DIRS=	share/doc/${PKGBASE}

REPLACE_PERL+=	hacks/*.pl hacks/*/*.pl

post-install:
	${CHMOD} a-x ${DESTDIR}${PREFIX}/share/applications/*.desktop
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/gle/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
BUILDLINK_API_DEPENDS.Xrandr+=	Xrandr>=1.0.2
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
