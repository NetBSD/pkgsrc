# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:16 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWWW_BUILDLINK3_MK:=	${LIBWWW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwww
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibwww}
BUILDLINK_PACKAGES+=	libwww

.if !empty(LIBWWW_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libwww+=	libwww>=5.3.2nb2
BUILDLINK_PKGSRCDIR.libwww?=	../../www/libwww
.endif	# LIBWWW_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
