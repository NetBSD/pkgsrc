# $NetBSD: buildlink3.mk,v 1.14 2008/01/18 05:09:51 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWWW_BUILDLINK3_MK:=	${LIBWWW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwww
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwww}
BUILDLINK_PACKAGES+=	libwww
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libwww

.if !empty(LIBWWW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libwww+=	libwww>=5.3.2nb2
BUILDLINK_ABI_DEPENDS.libwww+=	libwww>=5.4.0nb6
BUILDLINK_PKGSRCDIR.libwww?=	../../www/libwww
.endif	# LIBWWW_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := libwww
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libwww:Msocks4)
.include "../../net/socks4/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libwww:Msocks5)
.include "../../net/socks5/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
