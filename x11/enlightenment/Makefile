# $NetBSD: Makefile,v 1.47 2018/08/16 18:54:33 adam Exp $
#

DISTNAME=	enlightenment-0.17.3
PKGREVISION=	15
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightenment Window Manager, Development Release
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config automake autoconf

PKG_SYSCONFSUBDIR=	enlightenment
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

EGDIR=		${PREFIX}/share/examples/enlightenment
CONF_FILES=	${EGDIR}/sysactions.conf \
		${PKG_SYSCONFDIR}/sysactions.conf
CONF_FILES+=	${EGDIR}/enlightenment.menu \
		${PKG_SYSCONFBASE}/xdg/menus/enlightenment.menu

CONFIGURE_ARGS+=	--disable-mount-hal --disable-mount-udisks \
			--disable-mount-eeze
CONFIGURE_ENV+=		MODULE_ARCH="${LOWER_OPSYS}-${MACHINE_ARCH}"

BUILD_DEFS+=		PKG_SYSCONFBASE

INSTALLATION_DIRS=	${EGDIR}

SUBST_CLASSES.SunOS+=	solhost
SUBST_STAGE.solhost=	pre-configure
SUBST_FILES.solhost=	configure
SUBST_SED.solhost=	-e '/^MODULE_ARCH=/s/.host_os/solaris/'

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CPPFLAGS+=	-DPKGSRC_X11BASE=\"${X11BASE:Q}\"
.endif

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/etc/enlightenment.menu ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/data/etc/sysactions.conf ${DESTDIR}${EGDIR}

PKGCONFIG_OVERRIDE=	enlightenment.pc.in

MODULE_ARCH=	${LOWER_OPSYS}-${MACHINE_ARCH}-${PKGVERSION_NOREV}
PLIST_SUBST=	MODULE_ARCH=${MODULE_ARCH}
PRINT_PLIST_AWK+=	 { gsub(/${MODULE_ARCH}/, "$${MODULE_ARCH}") }

.include "../../devel/ecore/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/edje/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../graphics/evas-eet/buildlink3.mk"
.include "../../graphics/evas-jpeg/buildlink3.mk"
.include "../../graphics/evas-png/buildlink3.mk"
.include "../../sysutils/edbus/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.include "../../devel/eio/buildlink3.mk"
.include "../../x11/elementary/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
