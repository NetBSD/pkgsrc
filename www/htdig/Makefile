# $NetBSD: Makefile,v 1.1.1.1 1999/09/20 02:40:46 fredb Exp $
#

DISTNAME=	htdig-3.1.2
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/www/indexing/} \
		http://www.htdig.org/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.htdig.org/

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/sbin \
		--with-image-dir=${PREFIX}/share/httpd/htdocs/htdig \
		--with-search-dir=${PREFIX}/share/examples/htdig

.include "../../mk/bsd.pkg.mk"
