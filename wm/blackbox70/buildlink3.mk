# $NetBSD: buildlink3.mk,v 1.4 2020/10/02 16:40:32 gutteridge Exp $

BUILDLINK_TREE+=	blackbox70

.if !defined(BLACKBOX70_BUILDLINK3_MK)
BLACKBOX70_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blackbox70+=	blackbox70>=0.70.0
BUILDLINK_ABI_DEPENDS.blackbox70+=	blackbox70>=0.70.0
BUILDLINK_PKGSRCDIR.blackbox70?=	../../wm/blackbox70

pkgbase:= blackbox70
.include "../../mk/pkg-build-options.mk"

.include "../../x11/libX11/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.blackbox70:Mxft2}
.include "../../x11/libXft/buildlink3.mk"
.endif
.endif # BLACKBOX70_BUILDLINK3_MK

BUILDLINK_TREE+=	-blackbox70
