# $NetBSD: Makefile,v 1.26 2026/06/07 18:03:46 adam Exp $

PKGREVISION= 3
.include "../../www/curl/Makefile.common"

PKGNAME=	${DISTNAME:S/curl/libcurl-gnutls/}

TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}

INSTALLATION_DIRS+=	lib

.include "options.mk"

do-install:
.if ${OPSYS} == "Darwin"
	install_name_tool -id ${PREFIX}/lib/libcurl-gnutls.4.dylib \
		${WRKSRC}/lib/.libs/libcurl.4.dylib
	${INSTALL} ${WRKSRC}/lib/.libs/libcurl.4.dylib \
		${DESTDIR}${PREFIX}/lib/libcurl-gnutls.4.dylib
	cd ${DESTDIR}${PREFIX}/lib && \
		${LN} -s libcurl-gnutls.4.dylib libcurl-gnutls.dylib
.else
	cd ${WRKSRC} && ${PREFIX}/bin/patchelf \
		--set-soname 'libcurl-gnutls.so.4' \
		lib/.libs/libcurl.so.4.*
	${INSTALL} ${WRKSRC}/lib/.libs/libcurl.so.4.8.0 \
		${DESTDIR}${PREFIX}/lib/libcurl-gnutls.so.4.8.0
	cd ${DESTDIR}${PREFIX}/lib && \
		${LN} -s libcurl-gnutls.so.4.8.0 libcurl-gnutls.so && \
		${LN} -s libcurl-gnutls.so.4.8.0 libcurl-gnutls.so.4
.endif

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
