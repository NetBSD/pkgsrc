# $NetBSD: Makefile,v 1.7 2024/05/23 04:15:35 adam Exp $

.include "../../www/curl/Makefile.common"

PKGNAME=	${DISTNAME:S/curl/libcurl-gnutls/}

TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}

INSTALLATION_DIRS+=	lib

.include "options.mk"

do-install:
	cd ${WRKSRC} && \
		${PREFIX}/bin/patchelf \
		--set-soname 'libcurl-gnutls.so.4' \
		lib/.libs/libcurl.so.4.*
	${INSTALL} ${WRKSRC}/lib/.libs/libcurl.so.4.8.0 ${DESTDIR}${PREFIX}/lib/libcurl-gnutls.so.4.8.0
	cd ${DESTDIR}${PREFIX}/lib && \
		${LN} -s libcurl-gnutls.so.4.8.0 libcurl-gnutls.so && \
		${LN} -s libcurl-gnutls.so.4.8.0 libcurl-gnutls.so.4

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
