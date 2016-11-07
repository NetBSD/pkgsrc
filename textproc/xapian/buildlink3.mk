# $NetBSD: buildlink3.mk,v 1.6 2016/11/07 13:02:17 schmonz Exp $

BUILDLINK_TREE+=	xapian

.if !defined(XAPIAN_BUILDLINK3_MK)
XAPIAN_BUILDLINK3_MK:=

# XXX do these depends change?
BUILDLINK_API_DEPENDS.xapian+=	xapian>=1.0.7
BUILDLINK_ABI_DEPENDS.xapian+=	xapian>=1.2.2nb1
BUILDLINK_PKGSRCDIR.xapian?=	../../textproc/xapian

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif # XAPIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapian
