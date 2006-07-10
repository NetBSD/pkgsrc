# $NetBSD: buildlink3.mk,v 1.17 2006/07/10 21:50:34 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XORG_LIBS_BUILDLINK3_MK:=	${XORG_LIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xorg-libs
.endif

#
# xorg-libs must come first so that packages listed later can overwrite
# any symlinks created by buildlinking xorg-libs.
#
BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxorg-libs}
BUILDLINK_PACKAGES:=	xorg-libs ${BUILDLINK_PACKAGES}
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xorg-libs

.include "../../mk/bsd.prefs.mk"

.if !empty(XORG_LIBS_BUILDLINK3_MK:M+)

BUILDLINK_API_DEPENDS.xorg-libs+=		xorg-libs>=6.9.0
BUILDLINK_ABI_DEPENDS.xorg-libs?=	xorg-libs>=6.9.0nb2
BUILDLINK_PKGSRCDIR.xorg-libs?=		../../x11/xorg-libs
BUILDLINK_LIBDIRS.xorg-libs?=		${X11ROOT_PREFIX}/lib
BUILDLINK_TRANSFORM.xorg-libs+=		-e "s|/${X11ROOT_PREFIX}/|/|"

.endif  # XORG_LIBS_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
