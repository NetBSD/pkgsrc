# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/03/22 16:07:33 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHTML36_BUILDLINK3_MK:=	${GTKHTML36_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml36
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhtml36}
BUILDLINK_PACKAGES+=	gtkhtml36

.if !empty(GTKHTML36_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkhtml36+=	gtkhtml36>=3.6.0
BUILDLINK_PKGSRCDIR.gtkhtml36?=	../../www/gtkhtml36
.endif	# GTKHTML36_BUILDLINK3_MK

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gal2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
