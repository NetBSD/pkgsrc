# $NetBSD: Makefile,v 1.7 2012/03/03 00:12:29 wiz Exp $
#

DISTNAME=	gtkada-${GTKADA_VERSION}
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	gtkada-rm-${GTKADA_VERSION}${EXTRACT_SUFX}

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://libre.adacore.com/libre/tools/gtkada/
COMMENT=	Ada graphical toolkit based on Gtk+
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config perl makeinfo
MAKE_JOBS_SAFE=		no

GTKADA_VERSION=		2.22
FULL_PATH=		/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin:${PREFIX}/lib/pkgconfig
MY_CONFIGURE_ENV=	PATH=${FULL_PATH}
MY_CONFIGURE_ENV+=	CC=gnatgcc
CONFIGURE_ARGS+=	--disable-nls
PKGCONFIG_OVERRIDE+=	projects/gtkada.pc.in

post-wrapper:
	# We disable at least the wrapper binaries on all GNAT AUX ports to
	# avoid linkage and build problems.  In this case we need the wrappers
	# for the sed transformation script.
	${RM} ${WRKDIR}/.wrapper/bin/*

do-configure:
	# OpenGL, Gnome, and glade are normally detected automatically, but
	# at least with OpenGL, there is an installation bug.  Rather than
	# test everything, patch-ad just disables support for these features.
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/lib/gnat/gtkada/IGNORE.ME

# gtk2 includes atk, glib and pango among others
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/gnat-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
