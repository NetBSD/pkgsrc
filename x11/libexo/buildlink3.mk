# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:14 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EXO_BUILDLINK3_MK:=	${EXO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	exo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nexo}
BUILDLINK_PACKAGES+=	exo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}exo

.if !empty(EXO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.exo+=		exo>=0.3.0
BUILDLINK_ABI_DEPENDS.exo?=	exo>=0.3.0nb3
BUILDLINK_PKGSRCDIR.exo?=	../../x11/libexo
.endif	# EXO_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
