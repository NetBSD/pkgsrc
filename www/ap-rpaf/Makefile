# $NetBSD: Makefile,v 1.1 2006/03/06 19:31:03 tv Exp $
#

DISTNAME=		mod_rpaf-0.5
PKGNAME=		${DISTNAME:S/mod_/ap-/}
CATEGORIES=		www
MASTER_SITES=		http://stderr.net/apache/rpaf/download/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://stderr.net/apache/rpaf/
COMMENT=		Remaps reverse-proxied connections to "real" requesting IPs

APACHE_MODULE=		# defined
INSTALLATION_DIRS=	share/doc

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_rpaf.c

do-install:
	cd ${WRKSRC} && ${APXS} -n rpaf_module -i mod_rpaf.la
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_rpaf.txt

.include "../../mk/apache.mk"

.if ${PKG_APACHE} != "apache13"
do-configure:
	${RM} -f ${WRKSRC}/mod_rpaf.c
	${CP} -f ${WRKSRC}/mod_rpaf-2.0.c ${WRKSRC}/mod_rpaf.c
.endif

.include "../../mk/bsd.pkg.mk"
