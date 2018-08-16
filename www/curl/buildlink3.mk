# $NetBSD: buildlink3.mk,v 1.40 2018/08/16 18:54:32 adam Exp $

BUILDLINK_TREE+=	curl

.if !defined(CURL_BUILDLINK3_MK)
CURL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.curl+=	curl>=7.12.3
BUILDLINK_ABI_DEPENDS.curl+=	curl>=7.61.0nb2
BUILDLINK_PKGSRCDIR.curl?=	../../www/curl

pkgbase:= curl
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.curl:Mlibssh2)
.  include "../../security/libssh2/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.curl:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.curl:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.curl:Mrtmp)
.  include "../../net/rtmpdump/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.curl:Midn)
.  include "../../devel/libidn2/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.curl:Mhttp2)
.  include "../../www/nghttp2/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # CURL_BUILDLINK3_MK

BUILDLINK_TREE+=	-curl
