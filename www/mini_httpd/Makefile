# $NetBSD: Makefile,v 1.9 2005/09/07 02:15:12 reed Exp $

DISTNAME=	mini_httpd-1.19
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.acme.com/software/mini_httpd/
COMMENT=	Small, forking webserver with IPv6 and SSL support

DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_ENV+=	PKG_CFLAGS="${CFLAGS}"

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=	-lssl -lcrypto -lcrypt

.if ${OPSYS} != "IRIX"
LDFLAGS+=	-lutil
.endif

INSTALLATION_DIRS=	man/man1 man/man8 sbin

do-install:
	for FILE in mini_httpd.8 htpasswd.1; do \
		${MV} -f ${WRKSRC}/$${FILE} ${WRKSRC}/$${FILE}.bak; \
		${SED} -e 's/\([^.]\)htpasswd/\1mhtpasswd/g' \
			-e 's/^htpasswd/m&/' \
			${WRKSRC}/$${FILE}.bak > ${WRKSRC}/$${FILE}; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/mini_httpd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/htpasswd ${PREFIX}/sbin/mhtpasswd
	${INSTALL_MAN} ${WRKSRC}/mini_httpd.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/htpasswd.1 ${PREFIX}/man/man1/mhtpasswd.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
