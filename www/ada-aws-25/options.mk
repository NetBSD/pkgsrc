# $NetBSD: options.mk,v 1.1 2025/09/04 13:02:46 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.adawebserver-25
PKG_SUPPORTED_OPTIONS=		ldap aws-libadalang aws-ssl-dynamic aws-xmlada
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl netlib
PKG_OPTIONS_GROUP.ssl=		openssl gnutls
PKG_OPTIONS_GROUP.netlib=	aws-ipv4 aws-ipv6
PKG_SUGGESTED_OPTIONS=		ldap aws-libadalang openssl aws-xmlada

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maws-xmlada)
CONFIGURE_ARGS+=	XMLADA=true
PLIST_SRC+=		PLIST.xml
.else
CONFIGURE_ARGS+=	XMLADA=false
.endif

.if !empty(PKG_OPTIONS:Maws-libadalang)
# LAL dependencies
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"
.include "../../devel/ada-langkit-support-25/buildlink3.mk"
.include "../../devel/ada-libadalang-25/buildlink3.mk"
CONFIGURE_ARGS+=	LAL=true
PLIST_SRC+=		PLIST.lal
.endif

.if !empty(PKG_OPTIONS:Maws-ipv4)
CONFIGURE_ARGS+=	NETLIB=ipv4
.endif

.if !empty(PKG_OPTIONS:Maws-ipv6)
CONFIGURE_ARGS+=	NETLIB=ipv6
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	SOCKET=openssl
PLIST_SRC+=		PLIST.openssl
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
BUILDLINK_DEPMETHOD.gnutls=	full
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=		SOCKET=gnutls
PLIST_SRC+=			PLIST.gnutls
.endif

.if empty(PKG_OPTIONS:Mopenssl) && empty(PKG_OPTIONS:Mgnutls)
PLIST_SRC+=		PLIST.nossl
.endif

.if !empty(PKG_OPTIONS:Maws-ssl-dynamic)
CONFIGURE_ARGS+=	SSL_DYNAMIC=true
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	LDAP=true
PLIST_SRC+=		PLIST.ldap
.endif
