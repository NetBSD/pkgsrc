# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/02/23 08:34:14 adam Exp $

BUILDLINK_TREE+=	xqilla

.if !defined(XQILLA_BUILDLINK3_MK)
XQILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xqilla+=	xqilla>=2.2.4
BUILDLINK_PKGSRCDIR.xqilla?=	../../textproc/xqilla

.include "../../textproc/xerces-c/buildlink3.mk"
.endif	# XQILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-xqilla
