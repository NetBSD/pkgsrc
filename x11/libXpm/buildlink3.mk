# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:45 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../graphics/xpm/buildlink3.mk"

BUILDLINK_PREFIX.libXpm=	${BUILDLINK_PREFIX.xpm}
.else

BUILDLINK_TREE+=	libXpm

.if !defined(LIBXPM_BUILDLINK3_MK)
LIBXPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXpm+=	libXpm>=3.5.4.2
BUILDLINK_PKGSRCDIR.libXpm?=	../../x11/libXpm

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXpm

.endif
