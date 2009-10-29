# $NetBSD: Makefile,v 1.12 2009/10/29 22:29:16 tnn Exp $
#

DISTNAME=		urlget-1.4
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Simple command-line tool to retrieve an HTTP URL

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=		svr4
.else
BUILD_TARGET=		bsd
.endif
INSTALL_TARGET=		inst-all
INSTALL_MAKE_FLAGS+=	DEST=${DESTDIR}${PREFIX}	\
			  MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
