# $NetBSD: Makefile,v 1.6 2000/07/27 12:42:08 jlam Exp $

DISTNAME=	thttpd-2.19
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.acme.com/software/thttpd/

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
GNU_CONFIGURE=	# defined

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
BUILD_DEFS+=	USE_INET6

pre-configure:
	${MV} ${WRKSRC}/extras/htpasswd.1 ${WRKSRC}/extras/thtpasswd.1
	${MV} ${WRKSRC}/extras/htpasswd.c ${WRKSRC}/extras/thtpasswd.c
	for file in thttpd.8 extras/Makefile.in extras/thtpasswd.c; do \
		${MV} -f ${WRKSRC}/$${file} ${WRKSRC}/$${file}.bak; \
		${SED} -e "s,htpasswd,thtpasswd,g" \
			< ${WRKSRC}/$${file}.bak > ${WRKSRC}/$${file}; \
	done

post-build:
	for file in thttpd.conf thttpd.sh; do \
		${SED} -e "s,@PREFIX@,${PREFIX},g" \
			< ${FILESDIR}/$${file} > ${WRKDIR}/$${file}; \
	done

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/www

post-install:
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf ${PREFIX}/share/examples
	${INSTALL_SCRIPT} ${WRKDIR}/thttpd.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/www
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/www
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
