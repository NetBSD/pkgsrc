# $NetBSD: Makefile,v 1.7 2010/02/20 14:58:45 joerg Exp $
#

DISTNAME=		mod_rpaf-0.5
PKGNAME=		${APACHE_PKG_PREFIX}-rpaf-0.5
CATEGORIES=		www
MASTER_SITES=		http://stderr.net/apache/rpaf/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://stderr.net/apache/rpaf/
COMMENT=		Remaps reverse-proxied connections to "real" requesting IPs

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		ap-rpaf-[0-9]*

APACHE_MODULE=		yes
INSTALLATION_DIRS=	share/doc

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_rpaf.${MODULE_EXT}
APACHE_MODULE_SRC=	mod_rpaf.c

INSTALLATION_DIRS+=	share/doc/mod_rpaf

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mod_rpaf.txt

.if ${PKG_APACHE} == "apache13"
MODULE_EXT=	so
.else
MODULE_EXT=	la
do-configure:
	${RM} -f ${WRKSRC}/mod_rpaf.c
	${CP} -f ${WRKSRC}/mod_rpaf-2.0.c ${WRKSRC}/mod_rpaf.c
.endif

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
