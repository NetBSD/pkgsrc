# $NetBSD: Makefile,v 1.8 2007/06/30 16:09:08 joerg Exp $
#

DISTNAME=		bw_mod-0.6
PKGNAME=		${APACHE_PKG_PREFIX}-bw-${DISTNAME:S/bw_mod-//}
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		http://ivn.cl/apache/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ivn.cl/apache/
COMMENT=		Class-based bandwidth limiting module for Apache 2

APACHE_MODULE=		# defined
INSTALLATION_DIRS=	share/doc

PKG_APACHE_ACCEPTED=	apache2 apache22

do-build:
	@${ECHO} '#include "${DISTNAME}.c"' >${WRKSRC}/mod_bw.c
	cd ${WRKSRC} && ${APXS} -c mod_bw.c

do-install:
	cd ${WRKSRC} && ${APXS} -n bw_module -i mod_bw.la
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.txt ${PREFIX}/share/doc/apache_mod_bw.txt

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
