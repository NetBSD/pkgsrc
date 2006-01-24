# $NetBSD: buildlink3.mk,v 1.5 2006/01/24 07:32:58 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBZVT_BUILDLINK3_MK:=	${LIBZVT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libzvt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibzvt}
BUILDLINK_PACKAGES+=	libzvt

.if !empty(LIBZVT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libzvt+=	libzvt>=2.0.1nb5
BUILDLINK_RECOMMENDED.libzvt+=	libzvt>=2.0.1nb7
BUILDLINK_PKGSRCDIR.libzvt?=	../../x11/libzvt
.endif	# LIBZVT_BUILDLINK3_MK

.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
