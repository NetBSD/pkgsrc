# $NetBSD: Makefile,v 1.1.1.1 2004/02/03 16:18:54 reed Exp $

DISTNAME=	mini_httpd-1.19
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.acme.com/software/mini_httpd/
COMMENT=	Small, forking webserver with IPv6 and SSL support

USE_BUILDLINK2=	yes
MAKE_ENV+=	PKG_CFLAGS="${CFLAGS}"
LDFLAGS+=	-lssl -lcrypto -lcrypt -lutil

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

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
