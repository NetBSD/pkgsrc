# $NetBSD: Makefile,v 1.2 2001/11/14 06:18:08 zuntum Exp $
#

DISTNAME=	cronolog-1.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.ford-mason.co.uk/resources/cronolog/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ford-mason.co.uk/resources/cronolog/
COMMENT=	Web log rotation utility that provides datestamp filenames

GNU_CONFIGURE=	YES

post-patch:
	${SED} "s,/www/sbin/cronolog,${PREFIX}/sbin/cronolog,g"		\
		${WRKSRC}/doc/cronolog.1m > ${WRKSRC}/doc/cronolog.1m.done
	${MV} ${WRKSRC}/doc/cronolog.1m.done ${WRKSRC}/doc/cronolog.1m

post-install:
	${MV} ${PREFIX}/man/man1/cronolog.1m ${PREFIX}/man/man8/cronolog.8
	${MV} ${PREFIX}/man/man1/cronosplit.1m ${PREFIX}/man/man8/cronosplit.8

.include "../../mk/bsd.pkg.mk"
