# $NetBSD: Makefile,v 1.5 2003/06/10 07:21:29 wiz Exp $
#

DISTNAME=	cronolog-1.6.2
CATEGORIES=	www
MASTER_SITES=	http://www.cronolog.org/download/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.cronolog.org/
COMMENT=	Web log rotation utility that provides datestamp filenames

GNU_CONFIGURE=	YES

post-patch:
	${SED} "s,/www/sbin/cronolog,${PREFIX}/sbin/cronolog,g"		\
		${WRKSRC}/doc/cronolog.1m > ${WRKSRC}/doc/cronolog.1m.done
	${MV} ${WRKSRC}/doc/cronolog.1m.done ${WRKSRC}/doc/cronolog.1m

post-install:
	${MV} ${PREFIX}/man/man1/cronolog.1m ${PREFIX}/man/man8/cronolog.8
	${MV} ${PREFIX}/man/man1/cronosplit.1m ${PREFIX}/man/man8/cronosplit.8

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
