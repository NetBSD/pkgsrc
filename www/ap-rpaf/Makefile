# $NetBSD: Makefile,v 1.5 2006/06/06 16:45:31 rillig Exp $
#

DISTNAME=		mod_rpaf-0.5
PKGNAME=		${APACHE_PKG_PREFIX}-rpaf-0.5
CATEGORIES=		www
MASTER_SITES=		http://stderr.net/apache/rpaf/download/

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://stderr.net/apache/rpaf/
COMMENT=		Remaps reverse-proxied connections to "real" requesting IPs

CONFLICTS=	ap-rpaf-[0-9]*

APACHE_MODULE=		yes
INSTALLATION_DIRS=	share/doc

.include "../../mk/bsd.prefs.mk"
.include "../../mk/apache.mk"

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_rpaf.c

do-install:
	cd ${WRKSRC} && ${APXS} -n rpaf_module -i mod_rpaf.${APXS_SUFFIX}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_rpaf.txt

APXS_SUFFIX?=		so

.if ${PKG_APACHE} != "apache13"
APXS_SUFFIX=		la
do-configure:
	${RM} -f ${WRKSRC}/mod_rpaf.c
	${CP} -f ${WRKSRC}/mod_rpaf-2.0.c ${WRKSRC}/mod_rpaf.c
.endif

.include "../../mk/bsd.pkg.mk"
