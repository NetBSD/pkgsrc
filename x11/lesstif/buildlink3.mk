# $NetBSD: buildlink3.mk,v 1.2 2004/09/28 12:52:14 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LESSTIF_BUILDLINK3_MK:=	${LESSTIF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	lesstif
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlesstif}
BUILDLINK_PACKAGES+=	lesstif

.if !empty(LESSTIF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.lesstif+=	lesstif>=0.91.4
BUILDLINK_PKGSRCDIR.lesstif?=	../../x11/lesstif
.endif	# LESSTIF_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
