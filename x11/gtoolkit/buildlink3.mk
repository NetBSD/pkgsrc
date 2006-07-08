# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:14 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTOOLKIT_BUILDLINK3_MK:=	${GTOOLKIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtoolkit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtoolkit}
BUILDLINK_PACKAGES+=	gtoolkit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtoolkit

.if !empty(GTOOLKIT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtoolkit+=	gtoolkit>=0.9.5nb5
BUILDLINK_ABI_DEPENDS.gtoolkit+=gtoolkit>=0.9.5nb7
BUILDLINK_ABI_DEPENDS.gtoolkit?=	gtoolkit>=0.9.5nb10
BUILDLINK_PKGSRCDIR.gtoolkit?=	../../x11/gtoolkit
.endif	# GTOOLKIT_BUILDLINK3_MK

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
