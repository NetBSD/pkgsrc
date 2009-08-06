# $NetBSD: buildlink3.mk,v 1.20 2009/08/06 13:09:28 tnn Exp $

BUILDLINK_TREE+=	firefox

.if !defined(FIREFOX_BUILDLINK3_MK)
FIREFOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firefox+=	firefox>=3.5.2
BUILDLINK_PKGSRCDIR.firefox?=	../../www/firefox

.endif	# FIREFOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-firefox
