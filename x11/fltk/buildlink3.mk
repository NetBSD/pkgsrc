# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:42 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FLTK_BUILDLINK3_MK:=	${FLTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fltk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfltk}
BUILDLINK_PACKAGES+=	fltk

.if !empty(FLTK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.fltk+=	fltk>=1.0.9
BUILDLINK_PKGSRCDIR.fltk?=	../../x11/fltk

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

.endif	# FLTK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
