# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:39 rillig Exp $

BUILDLINK_TREE+=	libXdmcp

.if !defined(LIBXDMCP_BUILDLINK3_MK)
LIBXDMCP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXdmcp+=	libXdmcp>=0.99
BUILDLINK_PKGSRCDIR.libXdmcp?=		../../x11/libXdmcp
.endif # LIBXDMCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXdmcp
