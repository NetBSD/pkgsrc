# $NetBSD: buildlink3.mk,v 1.5 2005/03/24 04:47:58 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDEBASE_BUILDLINK3_MK:=	${KDEBASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdebase
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdebase}
BUILDLINK_PACKAGES+=	kdebase

.if !empty(KDEBASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdebase+=	kdebase>=3.2.0
BUILDLINK_RECOMMENDED.kdebase?=	kdebase>=3.4.0
BUILDLINK_PKGSRCDIR.kdebase?=	../../x11/kdebase3
.endif	# KDEBASE_BUILDLINK3_MK

PKG_OPTIONS.kdebase?=   ${PKG_DEFAULT_OPTIONS}

BUILDLINK_DEPENDS.Xrandr+=      Xrandr>=1.0

.include "../../databases/openldap/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.if !empty(PKG_OPTIONS.kdebase:Msamba)
.  include "../../net/samba/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS.kdebase:Msasl2)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
