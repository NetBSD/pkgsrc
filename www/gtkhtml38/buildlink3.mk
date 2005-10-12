# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/12 21:50:51 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHTML38_BUILDLINK3_MK:=	${GTKHTML38_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml38
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml38}
BUILDLINK_PACKAGES+=	gtkhtml38

.if !empty(GTKHTML38_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkhtml38+=	gtkhtml38>=3.8.0
BUILDLINK_PKGSRCDIR.gtkhtml38?=	../../www/gtkhtml38
.endif	# GTKHTML38_BUILDLINK3_MK

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
