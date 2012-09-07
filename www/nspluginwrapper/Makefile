# $NetBSD: Makefile,v 1.30 2012/09/07 19:17:42 adam Exp $
#

DISTNAME=       nspluginwrapper-1.2.2
PKGREVISION=    13
CATEGORIES=     www
MASTER_SITES=   http://gwenole.beauchesne.info/projects/nspluginwrapper/files/
EXTRACT_SUFX=   .tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME:S/-/-i386-/}-1.x86_64.rpm

MAINTAINER=     abs@NetBSD.org
HOMEPAGE=       http://gwenole.beauchesne.info/projects/nspluginwrapper/
COMMENT=        Use Netscape compatible plugins from other platforms
LICENSE=	gnu-gpl-v2

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base gtk2 x11
NOT_FOR_PLATFORM=	Linux-*-*

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-x11-prefix=${X11BASE}

PLUGIN_SUBDIR=		lib/nspluginwrapper/i386/linux
PLUGIN_INSTDIR=		${PREFIX}/${PLUGIN_SUBDIR}
PLUGIN_SRCDIR=		${WRKDIR}/usr/${PLUGIN_SUBDIR}

LDFLAGS.DragonFly=	-lgmodule-2.0

SUBST_CLASSES+=		npviewer
SUBST_STAGE.npviewer=	post-build
SUBST_FILES.npviewer=	${PLUGIN_SRCDIR}/npviewer
SUBST_SED.npviewer=	-e "s|/usr/|${PREFIX}/|g"

PKG_DESTDIR_SUPPORT= 	user-destdir
INSTALLATION_DIRS=	${PLUGIN_INSTDIR}

post-install:
	${INSTALL_LIB} ${PLUGIN_SRCDIR}/libxpcom.so ${DESTDIR}${PLUGIN_INSTDIR}
	${INSTALL_SCRIPT} ${PLUGIN_SRCDIR}/npviewer ${DESTDIR}${PLUGIN_INSTDIR}
	${INSTALL_LIB} ${PLUGIN_SRCDIR}/npviewer.bin ${DESTDIR}${PLUGIN_INSTDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
