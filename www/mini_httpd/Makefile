# $NetBSD: Makefile,v 1.15 2007/09/08 21:58:02 jlam Exp $

DISTNAME=	mini_httpd-1.19
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.acme.com/software/mini_httpd/
COMMENT=	Small, forking webserver with IPv6 and SSL support

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_FEATURES=	snprintf

MAKE_ENV+=	PKG_CFLAGS=${CFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=	-lssl -lcrypto -lcrypt

.if ${OPSYS} != "IRIX"
LDFLAGS+=	-lutil
.endif

MAKE_ENV+=	LDLIBS=${LIBS:Q}

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8 sbin

do-install:
	for FILE in mini_httpd.8 htpasswd.1; do \
		${MV} -f ${WRKSRC}/$${FILE} ${WRKSRC}/$${FILE}.bak; \
		${SED} -e 's/\([^.]\)htpasswd/\1mhtpasswd/g' \
			-e 's/^htpasswd/m&/' \
			${WRKSRC}/$${FILE}.bak > ${WRKSRC}/$${FILE}; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/mini_httpd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/htpasswd ${PREFIX}/sbin/mhtpasswd
	${INSTALL_MAN} ${WRKSRC}/mini_httpd.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/htpasswd.1 ${PREFIX}/${PKGMANDIR}/man1/mhtpasswd.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
