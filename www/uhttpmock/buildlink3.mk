# $NetBSD: buildlink3.mk,v 1.12 2018/12/09 18:52:10 adam Exp $

BUILDLINK_TREE+=	uhttpmock

.if !defined(UHTTPMOCK_BUILDLINK3_MK)
UHTTPMOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhttpmock+=	uhttpmock>=0.4.0
BUILDLINK_ABI_DEPENDS.uhttpmock?=	uhttpmock>=0.4.0nb18
BUILDLINK_PKGSRCDIR.uhttpmock?=		../../www/uhttpmock

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# UHTTPMOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhttpmock
