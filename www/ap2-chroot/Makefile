# $NetBSD: Makefile,v 1.13 2014/06/11 12:57:23 joerg Exp $

DISTNAME=	mod_chroot-0.5
PKGNAME=	${DISTNAME:S/mod_/${APACHE_PKG_PREFIX}-/}
CATEGORIES=	www security
MASTER_SITES=	http://core.segfault.pl/~hobbit/mod_chroot/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://core.segfault.pl/~hobbit/mod_chroot/
COMMENT=	Module to easily run Apache in a chroot environment
LICENSE=	gnu-gpl-v2

# functional conflict, apache>=2.2.10 has builtin ChrootDir directive support.
CONFLICTS+=	apache>=2.2.10

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	mod_chroot.la
NO_CONFIGURE=		yes

PKG_APACHE_ACCEPTED=	apache2
INSTALLATION_DIRS+=	share/doc/mod_chroot

post-install:
	${INSTALL_DATA} ${WRKSRC}/[A-Z]* ${DESTDIR}${PREFIX}/share/doc/mod_chroot/

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
