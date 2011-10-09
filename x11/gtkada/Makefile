# $NetBSD: Makefile,v 1.3 2011/10/09 23:57:09 marino Exp $
#

DISTNAME=	gtkada-2.22
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://libre.adacore.com/libre/tools/gtkada/
COMMENT=	Ada graphical toolkit based on Gtk+
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
MAKE_JOBS_SAFE=		no

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
	${TOUCH} ${DESTDIR}${PREFIX}/share/doc/gtkada/gtkada_rm/IGNORE.ME

# gtk2 includes atk, glib and pango among others
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/gnat-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
