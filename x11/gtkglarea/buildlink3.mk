# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:17 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKGLAREA_BUILDLINK3_MK:=	${GTKGLAREA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkglarea
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkglarea}
BUILDLINK_PACKAGES+=	gtkglarea

.if !empty(GTKGLAREA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkglarea+=	gtkglarea>=1.2.2nb3
BUILDLINK_PKGSRCDIR.gtkglarea?=	../../x11/gtkglarea
.endif	# GTKGLAREA_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
