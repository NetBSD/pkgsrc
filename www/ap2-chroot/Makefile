# $NetBSD: Makefile,v 1.3 2006/01/24 07:32:43 wiz Exp $

DISTNAME=	mod_chroot-0.3
PKGNAME=	ap2-chroot-0.3
PKGREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	http://core.segfault.pl/~hobbit/mod_chroot/dist/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://core.segfault.pl/~hobbit/mod_chroot/
COMMENT=	Module to easily run Apache in a chroot environment

APACHE_MODULE=		# defined
NO_CONFIGURE=		yes

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_chroot.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_chroot.la
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_chroot
	cd ${WRKSRC} && ${INSTALL_DATA} [A-Z]* ${PREFIX}/share/doc/mod_chroot/

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
