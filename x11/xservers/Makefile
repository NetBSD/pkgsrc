# $NetBSD: Makefile,v 1.34 2009/06/14 22:12:45 joerg Exp $

DISTNAME=	xservers-3.3.6.5
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	Old X11 servers for use under XFree86 4.x

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL.

BUILD_TARGET=	World
PLIST_SRC=	${WRKDIR}/PLIST

X11_SUBDIR=	X11R6.3

MESSAGE_SUBST+=	X11_SUBDIR=${X11_SUBDIR}

BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/X11R6.3/lib

do-configure:
	${SED} -e 's#@PROJECTROOT@#${PREFIX}/${X11_SUBDIR}#' \
	  ${FILESDIR}/host.def >${WRKSRC}/config/cf/host.def
	${ECHO} "#define NetBSDThreads NO" >>${WRKSRC}/config/cf/host.def

post-install:
	cd ${PREFIX} && \
	${FIND} ${X11_SUBDIR} \! -type d -print | ${SORT} >${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
