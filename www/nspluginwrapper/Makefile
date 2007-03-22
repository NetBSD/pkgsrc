# $NetBSD: Makefile,v 1.1.1.1 2007/03/22 22:33:45 abs Exp $
#

DISTNAME=       nspluginwrapper-0.9.91.3
CATEGORIES=     www
MASTER_SITES=   http://gwenole.beauchesne.info/projects/nspluginwrapper/files/
EXTRACT_SUFX=   .tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${RPMFILE}

MAINTAINER=     abs@NetBSD.org
HOMEPAGE=       http://gwenole.beauchesne.info/projects/nspluginwrapper/
COMMENT=        Use Netscape compatible plugins from other platforms

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
CONFIGURE_ARGS+= --prefix=${PREFIX} --x11=${X11BASE}

RPMFILE=	${DISTNAME:S:-:-i386-:}-1.x86_64.rpm
BUILD_DEPENDS+=	rpm2pkg>=1.2:../../pkgtools/rpm2pkg
RPM2PKG=	rpm2pkg
RPM2PKGARGS=	${DISTDIR}/${DIST_SUBDIR}/${RPMFILE}
LINUXLIBDIR=	${PREFIX}/lib/nspluginwrapper/i386/linux

SUBST_CLASSES+=		npviewer
SUBST_STAGE.npviewer=	post-build
SUBST_FILES.npviewer=	../i386/linux/npviewer
SUBST_SED.npviewer=	-e "s|/usr/|${PREFIX}/|g"

post-extract:
	${RPM2PKG} -d ${WRKDIR} -s 4 ${RPM2PKGARGS}

post-install:
	${MKDIR} ${LINUXLIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/i386/linux/libxpcom.so ${LINUXLIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/i386/linux/npviewer ${LINUXLIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/i386/linux/npviewer.bin ${LINUXLIBDIR}

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
