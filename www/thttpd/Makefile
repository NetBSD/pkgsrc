# $NetBSD: Makefile,v 1.25 2003/10/27 20:29:52 cube Exp $

DISTNAME=	thttpd-2.24
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.acme.com/software/thttpd/
COMMENT=	Tiny/turbo/throttling HTTP server

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
GNU_CONFIGURE=	# defined

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
BUILD_DEFS+=	USE_INET6

USE_PKGINSTALL=	yes
EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/thttpd.conf ${PKG_SYSCONFDIR}/thttpd.conf
RCD_SCRIPTS=	thttpd

pre-configure:
	${MV} ${WRKSRC}/extras/htpasswd.1 ${WRKSRC}/extras/thtpasswd.1
	${MV} ${WRKSRC}/extras/htpasswd.c ${WRKSRC}/extras/thtpasswd.c
	for FILE in thttpd.8 extras/Makefile.in extras/thtpasswd.c; do	\
		${MV} -f ${WRKSRC}/$${FILE} ${WRKSRC}/$${FILE}.bak;	\
		${SED}	-e "s,\.htpasswd,XXX,g;s,htpasswd,thtpasswd,g;s,XXX,.htpasswd,g" \
			${WRKSRC}/$${FILE}.bak > ${WRKSRC}/$${FILE};	\
	done

post-build:
	for FILE in thttpd.conf; do					\
		${SED} ${FILES_SUBST_SED}				\
			${FILESDIR}/$${FILE} > ${WRKDIR}/$${FILE};	\
	done

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/thttpd

post-install:
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf ${PREFIX}/share/examples
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/thttpd
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/thttpd

.include "../../mk/bsd.pkg.mk"
