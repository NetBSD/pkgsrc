# $NetBSD: Makefile,v 1.11 2001/02/17 17:22:41 wiz Exp $

DISTNAME=	thttpd-2.20b
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.acme.com/software/thttpd/
COMMENT=	tiny/turbo/throttling HTTP server

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
GNU_CONFIGURE=	# defined

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
BUILD_DEFS+=	USE_INET6

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/thttpd
	${SED}	-e "s,@CAT@,${CAT},g" \
		-e "s,@RM@,${RM},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@CAT@,${CAT},g" \
		-e "s,@CHMOD@,${CHMOD},g" \
		-e "s,@CP@,${CP},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf ${PREFIX}/share/examples
	${INSTALL_SCRIPT} ${WRKDIR}/thttpd.sh ${PREFIX}/etc/rc.d/thttpd
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/thttpd
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/thttpd
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
