# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:44 joerg Exp $

BUILDLINK_TREE+=	libXdmcp

.if !defined(LIBXDMCP_BUILDLINK3_MK)
LIBXDMCP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXdmcp+=	libXdmcp>=0.99
BUILDLINK_PKGSRCDIR.libXdmcp?=	../../x11/libXdmcp
.endif # LIBXDMCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXdmcp
