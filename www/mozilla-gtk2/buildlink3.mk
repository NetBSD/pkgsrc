# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 13:24:23 jmmv Exp $
#
# This Makefile fragment is included by packages that use mozilla-gtk2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MOZILLA_GTK2_BUILDLINK3_MK:=	${MOZILLA_GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mozilla-gtk2
.endif

.if !empty(MOZILLA_GTK2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			mozilla-gtk2
BUILDLINK_DEPENDS.mozilla-gtk2+=	mozilla-gtk2>=1.6nb1
BUILDLINK_PKGSRCDIR.mozilla-gtk2?=	../../www/mozilla-gtk2

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # MOZILLA_GTK2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
