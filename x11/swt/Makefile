# $NetBSD: Makefile,v 1.4 2023/11/14 14:03:21 wiz Exp $

VERSION=	4.21
PKGNAME=	swt-${VERSION}
PKGREVISION=	3
DISTNAME=	swt-${VERSION}-gtk-linux-x86_64
CATEGORIES=	graphics java x11
MASTER_SITES=   http://archive.eclipse.org/eclipse/downloads/drops4/R-${VERSION}-202109060500/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.eclipse.org/swt/
COMMENT=	Standard Widget Toolkit for Java
LICENSE=	epl-v2.0

USE_TOOLS+=	gmake pkg-config
USE_JAVA=	yes

USE_LANGUAGES=	c c++11

SWT_VERSION=    4946r21

MAKE_FILE=	make_netbsd.mak
MAKE_ENV+=	SWT_VERSION=${SWT_VERSION} MAKE_CAIRO=make_cairo
PLIST_SUBST+=	SWT_VERSION=${SWT_VERSION}

SUBST_CLASSES+=			fix-rpaths
SUBST_FILES.fix-rpaths=		make_netbsd.mak
SUBST_MESSAGE.fix-rpaths=	Fixing pkg-config rpath
SUBST_SED.fix-rpaths=		-e 's,--libs-only-L,--libs,g'
SUBST_STAGE.fix-rpaths=		pre-configure

post-extract:
	@${MKDIR} ${WRKSRC}
	(cd ${WRKSRC} && ${UNZIP_CMD} -qo ../*.zip)
	${CP} ${FILESDIR}/build.xml ${WRKSRC}/build.xml
	${CP} ${WRKSRC}/make_linux.mak ${WRKSRC}/make_netbsd.mak
	${CP} ${FILESDIR}/*.css ${WRKSRC}/org/eclipse/swt/internal/gtk/

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh

do-install:
	@${MKDIR} ${DESTDIR}${PREFIX}/lib/java/
	${INSTALL_LIB} ${WRKSRC}/libswt-*.so ${DESTDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKDIR}/swt.jar ${DESTDIR}${PREFIX}/lib/java/

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
