# $NetBSD: Makefile,v 1.13 1998/08/04 13:09:21 fvdl Exp $
#

DISTNAME=	mozilla-19980728
PKGNAME=	mozilla-19980728
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/source/ \
	ftp://sunsite.org.uk/Mirrors/ftp.mozilla.org/pub/mozilla/source/ \
	ftp://mirror.aarnet.edu.au/pub/mozilla/mozilla/source/

MAINTAINER=	fvdl@netbsd.org

USE_X11=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_MOTIF=	yes

CONFLICTS=	mozilla-19980603 mozilla-19980429

WRKSRC=		${WRKDIR}/mozilla

RELEASE!=	uname -r
MOZ_OBJDIR=	${OPSYS}${RELEASE}_OPT.OBJ
MOZ_LIBDIR=	${PREFIX}/lib/mozilla

MAKE_ENV+=	NO_SECURITY=1 MOZ_MEDIUM=1 MOZILLA_CLIENT=1 NO_MDUPDATE=1 BUILD_OPT=1 LIBRUNPATH=${MOZ_LIBDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/moz-export ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/mozilla-export ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/moz-export ${PREFIX}/bin/mozilla
	${INSTALL_PROGRAM_DIR} ${MOZ_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/*.so* ${MOZ_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${MOZ_OBJDIR}/lib/*.so* ${MOZ_LIBDIR}

.include "../../mk/bsd.pkg.mk"
