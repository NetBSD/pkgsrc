# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:15 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBZVT_BUILDLINK3_MK:=	${LIBZVT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libzvt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibzvt}
BUILDLINK_PACKAGES+=	libzvt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libzvt

.if !empty(LIBZVT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libzvt+=	libzvt>=2.0.1nb5
BUILDLINK_ABI_DEPENDS.libzvt+=	libzvt>=2.0.1nb9
BUILDLINK_PKGSRCDIR.libzvt?=	../../x11/libzvt
.endif	# LIBZVT_BUILDLINK3_MK

.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
