# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/29 04:50:56 xtraeme Exp $

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

.if !empty(XORG_LIBS_BUILDLINK3_MK:M+)

BUILDLINK_DEPENDS.xorg-libs+=	xorg-libs>=6.7.0
BUILDLINK_PKGSRCDIR.xorg-libs?=	../../x11/xorg-libs
BUILDLINK_TRANSFORM.xorg-libs+=	-e "s|/X11R6/|/|"

.endif  # XORG_LIBS_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
