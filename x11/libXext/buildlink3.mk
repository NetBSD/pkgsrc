# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:44 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/xext.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXext

.if !defined(LIBXEXT_BUILDLINK3_MK)
LIBXEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXext+=	libXext>=0.99.0
BUILDLINK_PKGSRCDIR.libXext?=	../../x11/libXext

.include "../../x11/libX11/buildlink3.mk"
# XXX don't include xextproto/bl3 here; packages checking for xext.pc must
# include it theirselfes
.endif # LIBXEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXext

.endif
