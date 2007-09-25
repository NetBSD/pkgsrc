# $NetBSD: Makefile,v 1.15 2007/09/25 10:07:06 hira Exp $
#

DISTNAME=	cronolog-1.6.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://cronolog.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cronolog.org/
COMMENT=	Web log rotation utility that provides datestamp filenames

GNU_CONFIGURE=	YES
INFO_FILES=	yes
USE_TOOLS+=	perl:run
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8

SUBST_CLASSES+=	cl
SUBST_STAGE.cl=	pre-configure
SUBST_FILES.cl=	doc/cronolog.1m
SUBST_SED.cl=	-e "s,/www/sbin/cronolog,${PREFIX}/sbin/cronolog,g"

post-install:
	cd ${PREFIX}/${PKGMANDIR} && mv man1/cronolog.1m man8/cronolog.8
	cd ${PREFIX}/${PKGMANDIR} && mv man1/cronosplit.1m man8/cronosplit.8

.include "../../mk/bsd.pkg.mk"
