# $NetBSD: Makefile,v 1.7 2007/06/30 16:09:08 joerg Exp $

DISTNAME=	mod_chroot-0.3
PKGNAME=	${APACHE_PKG_PREFIX}-chroot-0.3
PKGREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	http://core.segfault.pl/~hobbit/mod_chroot/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://core.segfault.pl/~hobbit/mod_chroot/
COMMENT=	Module to easily run Apache in a chroot environment

APACHE_MODULE=		# defined
NO_CONFIGURE=		yes

PKG_APACHE_ACCEPTED=	apache2 apache22

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_chroot.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_chroot.la
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_chroot
	cd ${WRKSRC} && ${INSTALL_DATA} [A-Z]* ${PREFIX}/share/doc/mod_chroot/

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
