# $NetBSD: buildlink3.mk,v 1.5 2004/09/21 16:52:41 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHTML3_BUILDLINK3_MK:=	${GTKHTML3_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml3
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml3}
BUILDLINK_PACKAGES+=	gtkhtml3

.if !empty(GTKHTML3_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkhtml3+=	gtkhtml3>=3.2.1
BUILDLINK_PKGSRCDIR.gtkhtml3?=	../../www/gtkhtml3
.endif	# GTKHTML3_BUILDLINK3_MK

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gal2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
