# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:33 joerg Exp $

BUILDLINK_TREE+=	xapian

.if !defined(XAPIAN_BUILDLINK3_MK)
XAPIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapian+=	xapian>=1.0.7
BUILDLINK_PKGSRCDIR.xapian?=	../../textproc/xapian
.endif # XAPIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapian
