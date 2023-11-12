# $NetBSD: buildlink3.mk,v 1.3 2023/11/12 13:24:13 wiz Exp $

BUILDLINK_TREE+=	libXaw3dXft

.if !defined(LIBXAW3DXFT_BUILDLINK3_MK)
LIBXAW3DXFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXaw3dXft+=	libXaw3dXft>=1.6.2h
BUILDLINK_ABI_DEPENDS.libXaw3dXft?=	libXaw3dXft>=1.6.2hnb3
BUILDLINK_PKGSRCDIR.libXaw3dXft?=	../../x11/libXaw3dXft

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif	# LIBXAW3DXFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXaw3dXft
