# $NetBSD: buildlink3.mk,v 1.20 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MOZILLA_GTK2_BUILDLINK3_MK:=		${MOZILLA_GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			mozilla-gtk2
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Nmozilla-gtk2}
BUILDLINK_PACKAGES+=			mozilla-gtk2
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mozilla-gtk2

.if !empty(MOZILLA_GTK2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.mozilla-gtk2+=	mozilla-gtk2>=1.7.5
BUILDLINK_ABI_DEPENDS.mozilla-gtk2+=	mozilla-gtk2>=1.7.13
BUILDLINK_PKGSRCDIR.mozilla-gtk2?=	../../www/mozilla-gtk2
.endif	# MOZILLA_GTK2_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
