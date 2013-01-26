# $NetBSD: buildlink3.mk,v 1.17 2013/01/26 21:36:53 adam Exp $

BUILDLINK_TREE+=	gnustep-preferences

.if !defined(GNUSTEP_PREFERENCES_BUILDLINK3_MK)
GNUSTEP_PREFERENCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-preferences+=	gnustep-preferences>=1.2.0nb19
BUILDLINK_ABI_DEPENDS.gnustep-preferences?=	gnustep-preferences>=1.2.0nb21
BUILDLINK_PKGSRCDIR.gnustep-preferences?=	../../x11/gnustep-preferences

BUILDLINK_INCDIRS.gnustep-preferences+=	lib/GNUstep/Frameworks/PrefsModule.framework/Headers
BUILDLINK_FILES.gnustep-preferences+=	lib/GNUstep/Frameworks/PrefsModule.framework/Headers/*.h
BUILDLINK_FILES.gnustep-preferences+=	include/PrefsModule/PrefsModule.h

#.include "../../x11/gnustep-back/buildlink3.mk"
.endif	# GNUSTEP_PREFERENCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-preferences
