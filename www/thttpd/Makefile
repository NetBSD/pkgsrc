# $NetBSD: Makefile,v 1.3 1999/12/15 14:48:48 abs Exp $

DISTNAME=	thttpd-2.09
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.acme.com/software/thttpd/

EXTRACT_ONLY=	${DISTFILES:N*.gif}
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
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/www/index.html

post-install:
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif \
	  ${PREFIX}/share/www

.include "../../mk/bsd.pkg.mk"
