# $NetBSD: Makefile,v 1.3 1998/07/13 18:20:08 tron Exp $

DISTNAME=	wwwoffle-2.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		ftp://sunsite.unc.edu/pub/Linux/apps/www/servers/
EXTRACT_SUFX=	.tgz

MAINTAINER=	magick@bundy.lip.owl.de

CONFLICTS=	wwwoffle-2.1c

USE_GMAKE=	yes
NO_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST

post-build:
	@${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/wwwoffle.sh \
	  >${WRKDIR}/wwwoffle.sh
	@${SH} ${SCRIPTDIR}/plist ${PREFIX} ${PKGDIR}/PLIST ${PLIST_SRC}

pre-install:
	${MKDIR} ${PREFIX}/etc/wwwoffle

post-install:
	${CP} ${PREFIX}/etc/wwwoffle/wwwoffle.conf \
	  ${PREFIX}/etc/wwwoffle/wwwoffle.conf.default
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffle.sh ${PREFIX}/etc/rc.d

.include "../../mk/bsd.pkg.mk"
