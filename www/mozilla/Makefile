# Makefile for mozilla package.
# Version required: 5.0b1 (3/31/98)
#
# $NetBSD: Makefile,v 1.1 1998/04/08 22:23:48 fvdl Exp $
#

DISTNAME=	unix
PKGNAME=	mozilla
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mozilla.org/pub/mozilla/1998-03-31/ \
	ftp://sunsite.org.uk/Mirrors/ftp.mozilla.org/pub/mozilla/1998-03-31/ \
	ftp://mirror.aarnet.edu.au/pub/mozilla/mozilla/1998-03-31/

MAINTAINER=	fvdl@netbsd.org

USE_X11=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
REQUIRES_MOTIF=	yes

WRKSRC=		${WRKDIR}/ns

RELEASE!=	uname -r
MOZ_OBJDIR=	${OPSYS}${RELEASE}_OPT.OBJ
MOZ_LIBDIR=	${PREFIX}/lib/mozilla

MAKE_ENV+=	NO_SECURITY=1 MOZ_MEDIUM=1 MOZILLA_CLIENT=1 NO_MDUPDATE=1 BUILD_OPT=1 LIBRUNPATH=${MOZ_LIBDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/moz-export ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/mozilla-export ${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${MOZ_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${MOZ_OBJDIR}/bin/*.so* ${MOZ_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${MOZ_OBJDIR}/lib/*.so* ${MOZ_LIBDIR}

.include <bsd.port.mk>
