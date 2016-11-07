# $NetBSD: buildlink3.mk,v 1.7 2016/11/07 13:46:45 wiz Exp $

BUILDLINK_TREE+=	xapian

.if !defined(XAPIAN_BUILDLINK3_MK)
XAPIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapian+=	xapian>=1.0.7
BUILDLINK_ABI_DEPENDS.xapian+=	xapian>=1.4.1
BUILDLINK_PKGSRCDIR.xapian?=	../../textproc/xapian

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif # XAPIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapian
