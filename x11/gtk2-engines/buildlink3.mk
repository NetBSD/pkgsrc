# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 22:39:45 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTK2_ENGINES_BUILDLINK3_MK:=	${GTK2_ENGINES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2-engines
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk2-engines}
BUILDLINK_PACKAGES+=	gtk2-engines
BUILDLINK_ORDER+=	gtk2-engines

.if !empty(GTK2_ENGINES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtk2-engines+=	gtk2-engines>=2.6.0
BUILDLINK_ABI_DEPENDS.gtk2-engines?=	gtk2-engines>=2.6.8nb1
BUILDLINK_PKGSRCDIR.gtk2-engines?=	../../x11/gtk2-engines
.endif	# GTK2_ENGINES_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
