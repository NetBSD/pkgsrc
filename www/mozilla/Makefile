# $NetBSD: Makefile,v 1.29 2000/06/14 16:43:25 soren Exp $
#

DISTNAME=	mozilla-20000612
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/source/ \
	http://download.sourceforge.net/mirrors/mozilla/ \
	ftp://sunsite.org.uk/Mirrors/ftp.mozilla.org/pub/mozilla/source/ \
	ftp://mirror.aarnet.edu.au/pub/mozilla/mozilla/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5
BUILD_DEPENDS+=	autoconf:../../devel/autoconf

USE_X11BASE=	yes
USE_GMAKE=	yes

MOZ_OBJDIR=	${OPSYS}${OS_VERSION}_OPT.OBJ
MOZ_LIBDIR=	${PREFIX}/lib/mozilla

MAKE_ENV+=	MOZILLA_CLIENT=1 NO_MDUPDATE=1 BUILD_OPT=1 \
		LIBRUNPATH=${MOZ_LIBDIR}

do-fetch:
	@${ECHO} XXX How to cvs checkout from a pserver non-interactively?

pre-configure:
	(cd ${WRKSRC} && autoconf)

pre-build:
	${ECHO} 0000000000 > ${WRKSRC}/build/build_number

do-build:
	(cd ${WRKSRC} && gmake -f client.mk)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/moz-export \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/mozilla-export \
		${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/moz-export ${PREFIX}/bin/mozilla
	${INSTALL_PROGRAM_DIR} ${MOZ_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/*.so.?.? ${MOZ_LIBDIR}

.include "../../mk/bsd.pkg.mk"
