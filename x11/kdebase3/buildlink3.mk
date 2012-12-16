# $NetBSD: buildlink3.mk,v 1.44 2012/12/16 01:52:40 obache Exp $

BUILDLINK_TREE+=	kdebase

.if !defined(KDEBASE_BUILDLINK3_MK)
KDEBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase+=	kdebase>=3.5.0nb2
BUILDLINK_ABI_DEPENDS.kdebase+=	kdebase>=3.5.10nb23
BUILDLINK_PKGSRCDIR.kdebase?=	../../x11/kdebase3

pkgbase := kdebase
.include "../../mk/pkg-build-options.mk"

BUILDLINK_API_DEPENDS.Xrandr+=	Xrandr>=1.0

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.kdebase:Msamba)
.  include "../../net/samba/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.kdebase:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.endif # KDEBASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase
