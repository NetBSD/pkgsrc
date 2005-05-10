# $NetBSD: Makefile,v 1.1.1.1 2005/05/10 17:00:39 tv Exp $
#

DISTNAME=		bw_mod-0.6
PKGNAME=		${DISTNAME:S/bw_mod/ap2-bw/}
CATEGORIES=		www
MASTER_SITES=		http://ivn.cl/apache/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://ivn.cl/apache/
COMMENT=		Class-based bandwidth limiting module for Apache 2

APACHE_MODULE=		# defined

do-build:
	@${ECHO} '#include "${DISTNAME}.c"' >${WRKSRC}/mod_bw.c
	cd ${WRKSRC} && ${APXS} -c mod_bw.c

do-install:
	cd ${WRKSRC} && ${APXS} -n bw_module -i mod_bw.la
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.txt ${PREFIX}/share/doc/apache_mod_bw.txt

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
