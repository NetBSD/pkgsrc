# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/10/01 12:48:05 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHTML30_BUILDLINK3_MK:=	${GTKHTML30_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml30
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml30}
BUILDLINK_PACKAGES+=	gtkhtml30

.if !empty(GTKHTML30_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkhtml30+=	gtkhtml30>=3.0.10
BUILDLINK_PKGSRCDIR.gtkhtml30?=	../../www/gtkhtml30
.endif	# GTKHTML30_BUILDLINK3_MK

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gal2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
