# $NetBSD: buildlink3.mk,v 1.16 2009/03/20 19:25:36 joerg Exp $

BUILDLINK_TREE+=	firefox-gtk1

.if !defined(FIREFOX_GTK1_BUILDLINK3_MK)
FIREFOX_GTK1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firefox-gtk1+=	firefox-gtk1>=2.0
BUILDLINK_ABI_DEPENDS.firefox-gtk1+=	firefox-gtk1>=2.0.0.3nb1
BUILDLINK_PKGSRCDIR.firefox-gtk1?=	../../www/firefox-gtk1
.endif # FIREFOX_GTK1_BUILDLINK3_MK

BUILDLINK_TREE+=	-firefox-gtk1
