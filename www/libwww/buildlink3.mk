# $NetBSD: buildlink3.mk,v 1.1 2004/02/12 21:39:32 minskim Exp $
#
# This Makefile fragment is included by packages that use libwww.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBWWW_BUILDLINK3_MK:=	${LIBWWW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libwww
.endif

.if !empty(LIBWWW_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libwww
BUILDLINK_DEPENDS.libwww+=		libwww>=5.3.2nb2
BUILDLINK_PKGSRCDIR.libwww?=		../../www/libwww

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # LIBWWW_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
