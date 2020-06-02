# $NetBSD: buildlink3.mk,v 1.6 2020/06/02 08:23:05 adam Exp $
#

BUILDLINK_TREE+=	libmatekbd

.if !defined(LIBMATEKBD_BUILDLINK3_MK)
LIBMATEKBD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatekbd+=	libmatekbd>=1.8.0
BUILDLINK_ABI_DEPENDS.libmatekbd+=	libmatekbd>=1.24.0nb1
BUILDLINK_PKGSRCDIR.libmatekbd?=	../../x11/libmatekbd

.include "../../x11/libxklavier/buildlink3.mk"
.endif	# LIBMATEKBD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatekbd
