# $NetBSD: buildlink3.mk,v 1.2 2004/03/06 23:46:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LABLGTK_BUILDLINK3_MK:=	${LABLGTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	lablgtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlablgtk}
BUILDLINK_PACKAGES+=	lablgtk

.if !empty(LABLGTK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.lablgtk+=	lablgtk>=1.2.5nb3
BUILDLINK_PKGSRCDIR.lablgtk?=	../../x11/lablgtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"

.endif	# LABLGTK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
