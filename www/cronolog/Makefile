# $NetBSD: Makefile,v 1.8 2003/08/09 11:32:31 seb Exp $
#

DISTNAME=	cronolog-1.6.2
CATEGORIES=	www
MASTER_SITES=	http://www.cronolog.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cronolog.org/
COMMENT=	Web log rotation utility that provides datestamp filenames

GNU_CONFIGURE=	YES
INFO_FILES=	cronolog.info

post-patch:
	${SED} "s,/www/sbin/cronolog,${PREFIX}/sbin/cronolog,g"		\
		${WRKSRC}/doc/cronolog.1m > ${WRKSRC}/doc/cronolog.1m.done
	${MV} ${WRKSRC}/doc/cronolog.1m.done ${WRKSRC}/doc/cronolog.1m

post-install:
	${MV} ${PREFIX}/man/man1/cronolog.1m ${PREFIX}/man/man8/cronolog.8
	${MV} ${PREFIX}/man/man1/cronosplit.1m ${PREFIX}/man/man8/cronosplit.8

.include "../../mk/bsd.pkg.mk"
