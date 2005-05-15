# $NetBSD: buildlink3.mk,v 1.11 2005/05/15 02:58:05 taya Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MOZILLA_BUILDLINK3_MK:=	${MOZILLA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mozilla
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmozilla}
BUILDLINK_PACKAGES+=	mozilla

.if !empty(MOZILLA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mozilla+=	mozilla>=1.7.5
BUILDLINK_RECOMMENDED.mozilla+=	mozilla>=1.7.8
BUILDLINK_PKGSRCDIR.mozilla?=	../../www/mozilla
.endif	# MOZILLA_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
