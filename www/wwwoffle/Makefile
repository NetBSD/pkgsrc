# $NetBSD: Makefile,v 1.6 1999/04/20 20:06:49 tron Exp $

DISTNAME=	wwwoffle-2.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		ftp://sunsite.unc.edu/pub/Linux/apps/www/servers/
EXTRACT_SUFX=	.tgz

MAINTAINER=	magick@bundy.lip.owl.de
HOMEPAGE=	http://www.gedanken.demon.co.uk/wwwoffle/

USE_GMAKE=	yes
NO_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST

post-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${FILESDIR}/wwwoffle.sh \
	  >${WRKDIR}/wwwoffle.sh
	@${SED} -e 's#@GTAR@#${GTAR}#g' <${PKGDIR}/PLIST >${PLIST_SRC}

pre-install:
	${MKDIR} ${PREFIX}/etc/wwwoffle

post-install:
	${CP} ${PREFIX}/etc/wwwoffle/wwwoffle.conf \
	  ${PREFIX}/etc/wwwoffle/wwwoffle.conf.default
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffle.sh ${PREFIX}/etc/rc.d
	${GTAR} czCf / ${PREFIX}/libdata/wwwoffle-spool.tar.gz var/wwwoffle

.include "../../mk/bsd.pkg.mk"
