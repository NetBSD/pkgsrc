# $NetBSD: buildlink3.mk,v 1.9 2005/05/15 02:58:05 taya Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MOZILLA_GTK2_BUILDLINK3_MK:=	${MOZILLA_GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mozilla-gtk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmozilla-gtk2}
BUILDLINK_PACKAGES+=	mozilla-gtk2

.if !empty(MOZILLA_GTK2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mozilla-gtk2+=	mozilla-gtk2>=1.7.5
BUILDLINK_RECOMMENDED.mozilla-gtk2+=	mozilla-gtk2>=1.7.8
BUILDLINK_PKGSRCDIR.mozilla-gtk2?=	../../www/mozilla-gtk2
.endif	# MOZILLA_GTK2_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
