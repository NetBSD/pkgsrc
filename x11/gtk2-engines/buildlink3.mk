# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 07:11:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gtk2-engines.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK2_ENGINES_BUILDLINK3_MK:=	${GTK2_ENGINES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2-engines
.endif

.if !empty(GTK2_ENGINES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gtk2-engines
BUILDLINK_DEPENDS.gtk2-engines+=	gtk2-engines>=2.2.0nb4
BUILDLINK_PKGSRCDIR.gtk2-engines?=	../../x11/gtk2-engines

.include "../../x11/gtk2/buildlink3.mk"

.endif # GTK2_ENGINES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
