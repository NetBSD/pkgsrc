# $NetBSD: buildlink3.mk,v 1.10 2022/01/18 02:48:33 pho Exp $

BUILDLINK_TREE+=	hs-X11

.if !defined(HS_X11_BUILDLINK3_MK)
HS_X11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-X11+=	hs-X11>=1.9.2
BUILDLINK_ABI_DEPENDS.hs-X11+=	hs-X11>=1.9.2nb2
BUILDLINK_PKGSRCDIR.hs-X11?=	../../x11/hs-X11

# Work around a Cabal bug. It ignores "ld-options" in X11.buildinfo
# while linking shared libraries:
# https://github.com/haskell/cabal/issues/4925
HASKELL_ENABLE_SHARED_LIBRARY=	no
# Note to devs: when you remove this please also remove it from
# ../../x11/hs-X11/Makefile

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.endif	# HS_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-X11
