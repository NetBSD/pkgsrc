# $NetBSD: Makefile,v 1.70 2026/02/06 08:44:47 wiz Exp $

DISTNAME=		rxvt-2.7.10
PKGREVISION=		11
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rxvt/}

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		https://sourceforge.net/projects/rxvt/
COMMENT=		Low memory usage xterm replacement that supports color
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		YES

BUILD_DEFS+=		VARBASE

USE_TOOLS+=		grep tbl

CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-lastlog \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-rxvt-scroll \
			--enable-next-scroll \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-ttygid \
			--enable-xgetdefault \
			--enable-frills \
			--enable-linespace \
			--enable-24bit \
			--enable-keepscrolling \
			--enable-mousewheel \
			--enable-greek \
			--enable-slipwheeling \
			--enable-languages \
			--with-encoding=noenc

CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.libXpm}/include/X11
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_PREFIX.libXpm}/lib

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	src/feature.h src/logging.h src/rxvt.h
SUBST_VARS.paths=	PREFIX VARBASE
SUBST_MESSAGE.paths=	Replacing path placeholders.

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin"
# Make rxvt setuid root so that tty ownership setting and utmp logging
# function correctly.
#
SPECIAL_PERMS=	${PREFIX}/bin/rxvt ${SETUID_ROOT_PERMS}
.endif

CFLAGS.SunOS+=	-DSunOS

# Make sure _NETBSD_SOURCE is defined for updlastlogx
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR}/app-defaults share/applications
CONF_FILES+=		${EGDIR}/app-defaults/Rxvt	\
			${PREFIX}/lib/X11/app-defaults/Rxvt

post-install:
	${INSTALL_DATA} ${FILESDIR}/Rxvt		\
		${DESTDIR}${PREFIX}/${EGDIR}/app-defaults
	${INSTALL_DATA} ${FILESDIR}/rxvt.desktop	\
		${DESTDIR}${PREFIX}/share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
