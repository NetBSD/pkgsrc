# $NetBSD: Makefile,v 1.9 2010/02/20 14:58:46 joerg Exp $

DISTNAME=	mod_chroot-0.3
PKGNAME=	${APACHE_PKG_PREFIX}-chroot-0.3
PKGREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	http://core.segfault.pl/~hobbit/mod_chroot/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://core.segfault.pl/~hobbit/mod_chroot/
COMMENT=	Module to easily run Apache in a chroot environment

PKG_DESTDIR_SUPPORT=	user-destdir

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	mod_chroot.la
NO_CONFIGURE=		yes

PKG_APACHE_ACCEPTED=	apache2 apache22
INSTALLATION_DIRS+=	share/doc/mod_chroot

post-install:
	${INSTALL_DATA} ${WRKSRC}/[A-Z]* ${DESTDIR}${PREFIX}/share/doc/mod_chroot/

.include "../../mk/apache.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
