# $NetBSD: buildlink3.mk,v 1.17 2020/11/05 09:07:13 ryoon Exp $

BUILDLINK_TREE+=	uhttpmock

.if !defined(UHTTPMOCK_BUILDLINK3_MK)
UHTTPMOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhttpmock+=	uhttpmock>=0.4.0
BUILDLINK_ABI_DEPENDS.uhttpmock?=	uhttpmock>=0.4.0nb28
BUILDLINK_PKGSRCDIR.uhttpmock?=		../../www/uhttpmock

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# UHTTPMOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhttpmock
