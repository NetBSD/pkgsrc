# $NetBSD: Makefile,v 1.30 2000/06/17 22:14:00 tsarna Exp $
#

DISTNAME=	mozilla-source-M16
PKGNAME=	mozilla-M16
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
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/moz-export \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/mozilla-export \
		${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/moz-export ${PREFIX}/bin/mozilla
	${INSTALL_PROGRAM_DIR} ${MOZ_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/*.so.?.? ${MOZ_LIBDIR}

.include "../../mk/bsd.pkg.mk"
