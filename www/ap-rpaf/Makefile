# $NetBSD: Makefile,v 1.11 2014/06/11 12:57:22 joerg Exp $
#

DISTNAME=		mod_rpaf-0.5
PKGNAME=		${APACHE_PKG_PREFIX}-rpaf-0.5
CATEGORIES=		www
MASTER_SITES=		http://stderr.net/apache/rpaf/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://stderr.net/apache/rpaf/
COMMENT=		Remaps reverse-proxied connections to "real" requesting IPs

CONFLICTS=		ap-rpaf-[0-9]*

APACHE_MODULE=		yes
INSTALLATION_DIRS=	share/doc

# does not compile with apache24
PKG_APACHE_ACCEPTED=	apache22

APACHE_MODULE_NAME=	mod_rpaf.${MODULE_EXT}
APACHE_MODULE_SRC=	mod_rpaf.c

INSTALLATION_DIRS+=	share/doc/mod_rpaf

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mod_rpaf.txt

MODULE_EXT=	la
do-configure:
	${RM} -f ${WRKSRC}/mod_rpaf.c
	${CP} -f ${WRKSRC}/mod_rpaf-2.0.c ${WRKSRC}/mod_rpaf.c

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
