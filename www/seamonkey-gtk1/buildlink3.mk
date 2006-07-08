# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:13 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
SEAMONKEY_GTK1_BUILDLINK3_MK:=		${SEAMONKEY_GTK1_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			seamonkey-gtk1
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Nseamonkey-gtk1}
BUILDLINK_PACKAGES+=			seamonkey-gtk1
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}seamonkey-gtk1

.if !empty(SEAMONKEY_GTK1_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.seamonkey-gtk1+=	seamonkey-gtk1>=1.0
BUILDLINK_ABI_DEPENDS.seamonkey-gtk1?=	seamonkey-gtk1>=1.0.1nb1
BUILDLINK_PKGSRCDIR.seamonkey-gtk1?=	../../www/seamonkey-gtk1
.endif	# SEAMONKEY_GTK1_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
