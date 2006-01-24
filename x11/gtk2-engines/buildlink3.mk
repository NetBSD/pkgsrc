# $NetBSD: buildlink3.mk,v 1.6 2006/01/24 07:32:54 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTK2_ENGINES_BUILDLINK3_MK:=	${GTK2_ENGINES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2-engines
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk2-engines}
BUILDLINK_PACKAGES+=	gtk2-engines

.if !empty(GTK2_ENGINES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtk2-engines+=	gtk2-engines>=2.6.0
BUILDLINK_RECOMMENDED.gtk2-engines?=	gtk2-engines>=2.6.6nb1
BUILDLINK_PKGSRCDIR.gtk2-engines?=	../../x11/gtk2-engines
.endif	# GTK2_ENGINES_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
