# $NetBSD: Makefile,v 1.4 2000/02/09 20:55:27 hubertf Exp $

DISTNAME=	thttpd-2.15
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.acme.com/software/thttpd/

EXTRACT_ONLY=	${DISTFILES:N*.gif}
GNU_CONFIGURE=	yes

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
# (Leave the above line in to still get it into the README-IPv6.html!)

pre-build:
	${MV} ${WRKSRC}/extras/htpasswd.1 ${WRKSRC}/extras/thtpasswd.1
	${MV} ${WRKSRC}/extras/Makefile ${WRKSRC}/extras/Makefile.orig
	${SED} -e "s/htpasswd/thtpasswd/g" \
	  <${WRKSRC}/extras/Makefile.orig >${WRKSRC}/extras/Makefile
	${SED} -e "s/htpasswd/thtpasswd/g" \
	  <${WRKSRC}/extras/htpasswd.c >${WRKSRC}/extras/thtpasswd.c

re-install:
	${MKDIR} ${PREFIX}/libexec/cgi-bin ${PREFIX}/share/www
	${SED} -e "s/htpasswd/thtpasswd/g" \
	  <${WRKSRC}/extras/htpasswd.1 >${WRKSRC}/extras/thtpasswd.1
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/www/index.html

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/www

post-install:
	${INSTALL_DATA} ${WRKSRC}/index.html \
	  ${PREFIX}/share/www
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif \
	  ${PREFIX}/share/www

.include "../../mk/bsd.pkg.mk"
