# $NetBSD: buildlink3.mk,v 1.26 2024/11/01 00:54:11 wiz Exp $

BUILDLINK_TREE+=	uhttpmock

.if !defined(UHTTPMOCK_BUILDLINK3_MK)
UHTTPMOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uhttpmock+=	uhttpmock>=0.4.0
BUILDLINK_ABI_DEPENDS.uhttpmock+=	uhttpmock>=0.11.0nb1
BUILDLINK_PKGSRCDIR.uhttpmock?=		../../www/uhttpmock

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.endif	# UHTTPMOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-uhttpmock
