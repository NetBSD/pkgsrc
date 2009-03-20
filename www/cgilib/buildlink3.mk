# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:36 joerg Exp $

BUILDLINK_TREE+=	cgilib

.if !defined(CGILIB_BUILDLINK3_MK)
CGILIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgilib+=	cgilib>=0.5nb1
BUILDLINK_ABI_DEPENDS.cgilib+=	cgilib>=0.5nb2
BUILDLINK_PKGSRCDIR.cgilib?=	../../www/cgilib
.endif # CGILIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgilib
