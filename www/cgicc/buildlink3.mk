# $NetBSD: buildlink3.mk,v 1.1 2011/03/17 14:48:50 adam Exp $

BUILDLINK_TREE+=	cgicc

.if !defined(CGICC_BUILDLINK3_MK)
CGICC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgicc+=	cgicc>=3.2.9
BUILDLINK_PKGSRCDIR.cgicc?=	../../www/cgicc
.endif	# CGICC_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgicc
