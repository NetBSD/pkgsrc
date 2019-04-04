# $NetBSD: Makefile,v 1.3 2019/04/04 02:24:40 jmmv Exp $

DISTNAME=	chunkwm-0.4.8
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=koekeishiya/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Tiling window manager for macOS based on plugin architecture
LICENSE=	mit

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LANGUAGES=		c99 c++11 obj-c++
USE_TOOLS=		gmake
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=		build
SUBST_STAGE.build=	pre-configure
SUBST_FILES.build=	makefile
SUBST_SED.build=	-e 's,GIT_VERSION.*=.*,GIT_VERSION=\\"${DISTNAME}\\",g'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	examples/chunkwmrc
SUBST_FILES.paths+=	examples/com.koekeishiya.chunkwm.plist
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.paths+=	-e 's,~/\.chunkwm_plugins,${PREFIX}/libexec/chunkwm,g'

CONF_FILES=	${PREFIX}/share/chunkwm/com.koekeishiya.chunkwm.plist \
		/Library/LaunchAgents/com.koekeishiya.chunkwm.plist

do-build:
.for d in . src/chunkc src/plugins/border src/plugins/ffm src/plugins/purify \
    src/plugins/template src/plugins/tiling
	cd ${WRKSRC}/${d} && gmake \
	    BUILD_FLAGS="-O2 -std=c++11 -Wall" \
	    PLUGINSDIR=${PREFIX}/libexec/chunkwm
.endfor

INSTALLATION_DIRS=	bin libexec/chunkwm share/chunkwm share/examples/chunkwm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chunkwm \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/chunkc/bin/chunkc \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/examples/chunkwmrc \
	    ${DESTDIR}${PREFIX}/share/examples/chunkwm
	${INSTALL_DATA} ${WRKSRC}/examples/com.koekeishiya.chunkwm.plist \
	    ${DESTDIR}${PREFIX}/share/chunkwm
	${INSTALL_LIB} ${WRKSRC}/plugins/*.so \
	    ${DESTDIR}${PREFIX}/libexec/chunkwm

.include "../../mk/bsd.pkg.mk"
