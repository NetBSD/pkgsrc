# $NetBSD: Makefile,v 1.31 2023/12/23 20:48:18 zafer Exp $
#

DISTNAME=	cronolog-1.6.2
PKGREVISION=	11
CATEGORIES=	www
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fordmason/cronolog/
COMMENT=	Web log rotation utility that provides datestamp filenames
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
INFO_FILES=		yes
USE_TOOLS+=		perl:run
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8

SUBST_CLASSES+=	cl
SUBST_STAGE.cl=	pre-configure
SUBST_FILES.cl=	doc/cronolog.1m
SUBST_SED.cl=	-e "s,/www/sbin/cronolog,${PREFIX}/sbin/cronolog,g"

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR} && mv man1/cronolog.1m man8/cronolog.8
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR} && mv man1/cronosplit.1m man8/cronosplit.8

.include "../../mk/bsd.pkg.mk"
