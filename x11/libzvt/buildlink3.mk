# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:42 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBZVT_BUILDLINK3_MK:=	${LIBZVT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libzvt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibzvt}
BUILDLINK_PACKAGES+=	libzvt

.if !empty(LIBZVT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libzvt+=	libzvt>=2.0.1nb5
BUILDLINK_PKGSRCDIR.libzvt?=	../../x11/libzvt

.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# LIBZVT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
