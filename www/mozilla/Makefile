# $NetBSD: Makefile,v 1.31 2000/06/19 04:15:32 soren Exp $
#

DISTNAME=	mozilla-source-M16
PKGNAME=	mozilla-m16
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/releases/m16/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5
BUILD_DEPENDS+=	autoconf:../../devel/autoconf
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk
DEPENDS+=	ORBit>=0.5.1:../../net/ORBit
#DEPENDS+=	jpeg-6b:../../graphics/jpeg
#DEPENDS+=	png>=1.0.6:../../graphics/png

#GNU_CONFIGURE=	yes
#CONFIGURE_ARGS=--with-jpeg=${LOCALBASE} --with-png=${LOCALBASE} \
#		--disable-pedantic --disable-debug

USE_X11BASE=	yes
USE_GMAKE=	yes

MOZ_OBJDIR=	${OPSYS}${OS_VERSION}_OPT.OBJ
MOZ_LIBDIR=	${PREFIX}/lib/mozilla

MAKE_ENV+=	MOZILLA_CLIENT=1 NO_MDUPDATE=1 BUILD_OPT=1 \
		LIBRUNPATH=${MOZ_LIBDIR}

pre-configure:
	(cd ${WRKSRC} && autoconf)

pre-build:
	${ECHO} 0000000000 > ${WRKSRC}/build/build_number

do-build:
	(cd ${WRKSRC} && ${GMAKE} -f client.mk build)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/mozilla \
		${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${MOZ_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/*.so.?.? ${MOZ_LIBDIR}

.include "../../mk/bsd.pkg.mk"
