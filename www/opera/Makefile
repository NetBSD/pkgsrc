# $NetBSD: Makefile,v 1.1.1.1 2000/10/27 04:12:22 tron Exp $

DISTNAME=	opera-4.0-b2-static.i386
PKGNAME=	opera-4.0b2
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/linux/tgz/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.opera.com/

DEPENDS+=	suse_libjpeg>=6.4:../../emulators/suse_libjpeg
DEPENDS+=	suse_x11>=6.3:../../emulators/suse_x11

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	opera-license

CHECK_SHLIBS=	NO
NO_BUILD=	YES

do-install:
	${MKDIR} ${PREFIX}/share/doc/opera ${PREFIX}/share/opera/styles
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} opera ${PREFIX}/bin && \
	${INSTALL_DATA} LICENSE README ${PREFIX}/share/doc/opera && \
	${INSTALL_DATA} opera.adr ${PREFIX}/share/opera && \
	${INSTALL_DATA} *.css ${PREFIX}/share/opera/styles

.include "../../mk/bsd.pkg.mk"
