# $NetBSD: buildlink3.mk,v 1.19 2008/03/02 14:40:26 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CURL_BUILDLINK3_MK:=	${CURL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	curl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncurl}
BUILDLINK_PACKAGES+=	curl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}curl

.if !empty(CURL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.curl+=	curl>=7.12.3
BUILDLINK_ABI_DEPENDS.curl+=	curl>=7.17.1nb1
BUILDLINK_PKGSRCDIR.curl?=	../../www/curl

pkgbase:= curl
.  include "../../mk/pkg-build-options.mk"
.  if !empty(PKG_BUILD_OPTIONS.curl:Mlibssh2)
.    include "../../security/libssh2/buildlink3.mk"
.  endif
.endif	# CURL_BUILDLINK3_MK

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
