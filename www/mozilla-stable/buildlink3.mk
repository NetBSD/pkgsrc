# $NetBSD: buildlink3.mk,v 1.4 2004/12/04 03:50:40 taya Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MOZILLA_STABLE_BUILDLINK3_MK:=	${MOZILLA_STABLE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mozilla-stable
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmozilla-stable}
BUILDLINK_PACKAGES+=	mozilla-stable

.if !empty(MOZILLA_STABLE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mozilla-stable+=	mozilla-stable>=1.7.3
BUILDLINK_PKGSRCDIR.mozilla-stable?=	../../www/mozilla-stable
.endif	# MOZILLA_STABLE_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
