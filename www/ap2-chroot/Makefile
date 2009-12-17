# $NetBSD: Makefile,v 1.8 2009/12/17 19:38:14 abs Exp $

DISTNAME=	mod_chroot-0.3
PKGNAME=	${APACHE_PKG_PREFIX}-chroot-0.3
PKGREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	http://core.segfault.pl/~hobbit/mod_chroot/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://core.segfault.pl/~hobbit/mod_chroot/
COMMENT=	Module to easily run Apache in a chroot environment

APACHE_MODULE=		yes
NO_CONFIGURE=		yes

PKG_APACHE_ACCEPTED=	apache2 apache22
INSTALLATION_DIRS+=	share/doc/mod_chroot

do-build:
	cd ${WRKSRC} && ${APXS} -c mod_chroot.c

do-install:
	cd ${WRKSRC} && ${APXS} -i mod_chroot.la
	cd ${WRKSRC} && ${INSTALL_DATA} [A-Z]* ${DESTDIR}${PREFIX}/share/doc/mod_chroot/

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
