# $NetBSD: Makefile,v 1.12 2016/10/19 18:43:58 bsiegert Exp $
#

DISTNAME=		mod_rpaf-0.8.4
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=gnif/}
GITHUB_PROJECT=		mod_rpaf
GITHUB_TAG=		v0.8.4

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/gnif/mod_rpaf/
COMMENT=		Remaps reverse-proxied connections to "real" requesting IPs
LICENSE=		apache-2.0

CONFLICTS=		ap-rpaf-[0-9]*

APACHE_MODULE=		yes
INSTALLATION_DIRS=	share/doc

APACHE_MODULE_NAME=	mod_rpaf.${MODULE_EXT}
APACHE_MODULE_SRC=	mod_rpaf.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/mod_rpaf.txt

MODULE_EXT=	la

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
