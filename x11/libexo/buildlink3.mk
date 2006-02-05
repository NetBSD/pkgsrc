# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:11:39 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EXO_BUILDLINK3_MK:=	${EXO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	exo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nexo}
BUILDLINK_PACKAGES+=	exo

.if !empty(EXO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.exo+=		exo>=0.3.0
BUILDLINK_RECOMMENDED.exo?=	exo>=0.3.0nb2
BUILDLINK_PKGSRCDIR.exo?=	../../x11/libexo
.endif	# EXO_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
