# $NetBSD: buildlink3.mk,v 1.2 2008/05/07 02:53:41 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NUCLEO_BUILDLINK3_MK:=	${NUCLEO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	nucleo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnucleo}
BUILDLINK_PACKAGES+=	nucleo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}nucleo

.if ${NUCLEO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.nucleo+=	nucleo>=0.6
BUILDLINK_PKGSRCDIR.nucleo?=	../../x11/nucleo
pkgbase:=nucleo
.  include "../../mk/pkg-build-options.mk"
.endif	# NUCLEO_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.nucleo:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.endif

#.if !empty(PKG_BUILD_OPTIONS.nucleo:Mqt4)
#.  include "../../x11/qt4-libs/buildlink3.mk"
#.endif

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg-devel/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
