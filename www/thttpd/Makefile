# $NetBSD: Makefile,v 1.2 1999/11/21 23:03:37 tron Exp $

DISTNAME=	thttpd-2.05
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.acme.com/software/thttpd/

GNU_CONFIGURE=	yes

pre-build:
	${MV} ${WRKSRC}/extras/Makefile ${WRKSRC}/extras/Makefile.orig
	${SED} -e "s/htpasswd/thtpasswd/g" \
	  <${WRKSRC}/extras/Makefile.orig >${WRKSRC}/extras/Makefile
	${SED} -e "s/htpasswd/thtpasswd/g" \
	  <${WRKSRC}/extras/htpasswd.c >${WRKSRC}/extras/thtpasswd.c

pre-install:
	${MKDIR} ${PREFIX}/libexec/cgi-bin ${PREFIX}/share/www
	${SED} -e "s/htpasswd/thtpasswd/g" \
	  <${WRKSRC}/extras/htpasswd.1 >${WRKSRC}/extras/thtpasswd.1
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/www

.include "../../mk/bsd.pkg.mk"
