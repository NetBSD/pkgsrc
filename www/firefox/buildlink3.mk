# $NetBSD: buildlink3.mk,v 1.18 2009/03/20 19:25:36 joerg Exp $

BUILDLINK_TREE+=	firefox

.if !defined(FIREFOX_BUILDLINK3_MK)
FIREFOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firefox+=	firefox>=2.0
BUILDLINK_API_DEPENDS.firefox+=	firefox<=2.99
BUILDLINK_ABI_DEPENDS.firefox+=	firefox>=2.0.0.3nb1
BUILDLINK_PKGSRCDIR.firefox?=	../../www/firefox
.endif # FIREFOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-firefox
