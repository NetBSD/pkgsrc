# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:37:02 wiz Exp $

BUILDLINK_TREE+=	c-icap

.if !defined(C_ICAP_BUILDLINK3_MK)
C_ICAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.c-icap+=	c-icap>=0.3.5
BUILDLINK_ABI_DEPENDS.c-icap?=	c-icap>=0.5.5nb4
BUILDLINK_PKGSRCDIR.c-icap?=	../../www/c-icap

.include "../../devel/zlib/buildlink3.mk"
.endif	# C_ICAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-c-icap
