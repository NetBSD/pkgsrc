# $NetBSD: Makefile,v 1.11 2006/06/25 08:59:22 rillig Exp $
#

DISTNAME=	cronolog-1.6.2
CATEGORIES=	www
MASTER_SITES=	http://www.cronolog.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cronolog.org/
COMMENT=	Web log rotation utility that provides datestamp filenames

GNU_CONFIGURE=	YES
INFO_FILES=	yes

post-patch:
	${SED} "s,/www/sbin/cronolog,${PREFIX}/sbin/cronolog,g"		\
		${WRKSRC}/doc/cronolog.1m > ${WRKSRC}/doc/cronolog.1m.done
	${MV} ${WRKSRC}/doc/cronolog.1m.done ${WRKSRC}/doc/cronolog.1m

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${MV} ${PREFIX}/man/man1/cronolog.1m ${PREFIX}/man/man8/cronolog.8
	${MV} ${PREFIX}/man/man1/cronosplit.1m ${PREFIX}/man/man8/cronosplit.8

.include "../../mk/bsd.pkg.mk"
