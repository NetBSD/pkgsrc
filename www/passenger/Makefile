# $NetBSD: Makefile,v 1.25 2024/05/29 16:34:54 adam Exp $

COMMENT=		Web and application server for Ruby, Python and Node.js
PKGREVISION=		19

.include "Makefile.common"

INSTALL_ENV+=		FS_PREFIX=${PREFIX}
INSTALL_ENV+=		FS_DOCDIR=${PREFIX}/share/doc
INSTALL_ENV+=		RUBYLIBDIR=${PREFIX}/${RUBY_VENDORLIB}
INSTALL_ENV+=		RUBYARCHDIR=${PREFIX}/${RUBY_VENDORARCHLIB}
INSTALL_ENV+=		APACHE2_MODULE_PATH=${PREFIX}/lib/httpd/mod_passenger.so
INSTALL_ENV+=		NATIVE_PACKAGING_METHOD=pkgsrc

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${RAKE} \
		agent nginx nginx:as_dynamic_module native_support

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} ${RAKE} fakeroot
	${INSTALL_MAN} ${WRKSRC}/man/passenger-config.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/passenger-memory-stats.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/man/passenger-status.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
