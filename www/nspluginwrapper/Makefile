# $NetBSD: Makefile,v 1.65 2018/11/12 03:53:05 ryoon Exp $
#

DISTNAME=	nspluginwrapper-1.4.4
PKGREVISION=	16
CATEGORIES=	www
MASTER_SITES=	http://nspluginwrapper.org/download/
MASTER_SITES+=	http://teokurebsd.org/netbsd/packages/distfiles/nspluginwrapper/
DISTFILES=	${DISTNAME}.tar.gz ${DISTNAME}-suse121-generic.${WRAPPER_ARCH}.tar.gz

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://nspluginwrapper.org/
COMMENT=	Use Netscape compatible plugins from other platforms
LICENSE=	gnu-gpl-v2

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base gtk2 x11
EMUL_REQD=		suse>=12.1
NOT_FOR_PLATFORM=	Linux-*-*

HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
WRAPPER_ARCH=		i386
.elif ${EMUL_PLATFORM} == "linux-x86_64"
WRAPPER_ARCH=		x86_64
.endif

PLUGIN_SUBDIR=		lib/nspluginwrapper/${WRAPPER_ARCH}/linux
PLUGIN_INSTDIR=		${PREFIX}/${PLUGIN_SUBDIR}
PLUGIN_SRCDIR=		${WRKDIR}/usr/${PLUGIN_SUBDIR}

LDFLAGS.DragonFly=	-lgmodule-2.0

SUBST_CLASSES+=		npw-config
SUBST_STAGE.npw-config=	pre-configure
SUBST_FILES.npw-config=	src/npw-config.c
SUBST_SED.npw-config=	-e "s|/usr/pkg/|${PREFIX}/|g"

SUBST_CLASSES+=		npviewer
SUBST_STAGE.npviewer=	post-build
SUBST_FILES.npviewer=	${PLUGIN_SRCDIR}/npviewer
SUBST_SED.npviewer=	-e "s|/usr/|${PREFIX}/|g"

INSTALLATION_DIRS=	${PLUGIN_INSTDIR}

post-install:
	${INSTALL_LIB} ${PLUGIN_SRCDIR}/libnoxshm.so ${DESTDIR}${PLUGIN_INSTDIR}
	${INSTALL_SCRIPT} ${PLUGIN_SRCDIR}/npviewer ${DESTDIR}${PLUGIN_INSTDIR}
	${INSTALL_LIB} ${PLUGIN_SRCDIR}/npviewer.bin ${DESTDIR}${PLUGIN_INSTDIR}

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
