# $NetBSD: buildlink3.mk,v 1.2 2015/06/12 23:39:11 taca Exp $

BUILDLINK_TREE+=	c-icap

.if !defined(C_ICAP_BUILDLINK3_MK)
C_ICAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.c-icap+=	c-icap>=0.3.5
BUILDLINK_PKGSRCDIR.c-icap?=	../../www/c-icap

.include "../../devel/zlib/buildlink3.mk"
.endif	# C_ICAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-c-icap
