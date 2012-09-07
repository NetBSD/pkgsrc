# $NetBSD: Makefile,v 1.9 2012/09/07 19:17:46 adam Exp $
#

DISTNAME=	gtkada-${GTKADA_VERSION}
PKGREVISION=	6
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
USE_TOOLS+=		gmake pkg-config perl makeinfo pkg-config
USE_LANGUAGES=		c ada c++ fortran
MAKE_JOBS_SAFE=		no

GTKADA_VERSION=		2.22
CONFIGURE_ARGS+=	--disable-nls
PKGCONFIG_OVERRIDE+=	projects/gtkada.pc.in

SUBST_CLASSES+= 	gate
SUBST_STAGE.gate=	pre-configure
SUBST_MESSAGE.gate=	Override tools for gate executable
SUBST_FILES.gate=	src/tools/gate.in
SUBST_SED.gate= 	-e "s,@DIFF@,${TOOLS_PLATFORM.diff},"
SUBST_SED.gate+=	-e "s,@PATCH@,${TOOLS_PLATFORM.patch},"

do-configure:
	# OpenGL, Gnome, and glade are normally detected automatically, but
	# at least with OpenGL, there is an installation bug.  Rather than
	# test everything, patch-ad just disables support for these features.
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

# gtk2 includes atk, glib and pango among others
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
