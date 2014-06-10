# $NetBSD: Makefile,v 1.11 2014/06/10 15:22:17 joerg Exp $
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

PKG_APACHE_ACCEPTED=	apache22

APACHE_MODULE_NAME=	mod_bw.la

INSTALLATION_DIRS+=	share/doc

post-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.txt ${DESTDIR}${PREFIX}/share/doc/apache_mod_bw.txt

.include "../../mk/apache.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
